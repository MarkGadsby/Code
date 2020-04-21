///////////////////////////////////////////////////////////////////////
// Main.C For the MusicPlayer program.
//
// Advanced Linux Sound Architecture (ALSA) is a software framework and 
// part of the Linux kernel that provides an application programming 
// interface (API) for sound card device drivers. 
//
// Vorbis is the Ogg Vorbis audio coding format 
//
// To build this file:
//
// gcc -W Main.c -o MusicPlayer -lasound -lvorbisfile -lmysqlclient
//
// This file will use the alsa lib to set up the pulse-code modulation interface 
// (PCM) to play output and use the vorbis lib to read in a .ogg file and pass
// it to the PCM
///////////////////////////////////////////////////////////////////////
#include <alsa/asoundlib.h>
#include <vorbis/vorbisfile.h>
#include <linux/limits.h>
#include <dirent.h>
#include "MusicPlayer.h"
#include <stdbool.h>
#include <mysql/mysql.h>

const int SAMPLE_RATE = 44100;          // frequency in Hz

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("\nUseage: ./MusicPlayer \"Artist\"\n\n");
        return 0;
    }

    char PlayPath[PATH_MAX];

    GetPathFromArtist(PlayPath, argv[1]);

    struct TrackInfo trackArray[30]; // Allocate track info
    memset(trackArray, 0, 30 * sizeof(struct TrackInfo));

    int ArrayTotal = 0;
    FillTrackFile(trackArray, PlayPath, &ArrayTotal);
    FillVorbisInfo(trackArray, PlayPath, ArrayTotal);
    BubbleSortTracks(trackArray, ArrayTotal);

    snd_pcm_t* pcmHandle = NULL;        // PCM handle

    OpenPCM(&pcmHandle);

    unsigned long pcmPeriodSize = SetupPCM(pcmHandle);

    for (int i = 0; i < ArrayTotal; i++)
    {
        printf("Now playing: %s by %s\n", trackArray[i].Title, trackArray[i].Artist);

        // Allocate buffer to hold a single PCM period
        // bufferSize = PCM period * 2 channels * 2 byte format
        int bufferSize = pcmPeriodSize * 2 * 2;
        char* buffer = (char*) malloc(bufferSize);

        int current_section = 0;
        long bytesRead = 0;

        do  // pass a buffer of data from the file to the PCM 
        {
            bytesRead = ov_read(&trackArray[i].VorbisFile, buffer, bufferSize, 0, 2, 1, &current_section);

            // bytesRead will four times as large as snd_pcm_writei is expecting 
            // (2 channels, 2 byte data format)  
            if (snd_pcm_writei(pcmHandle, buffer, bytesRead / 4) < 0)
                snd_pcm_prepare(pcmHandle);
        }
        while(bytesRead);

        ov_clear(&trackArray[i].VorbisFile);   // clear the decoder's buffers
        free(buffer);                           // free the buffer memory
        snd_pcm_drain(pcmHandle);               // stop a PCM preserving pending frames
    }

    snd_pcm_close(pcmHandle);   // close PCM handle 

    return 1;
}

void OpenPCM(snd_pcm_t** ppcmHandle)
{
    // Playback device
    static char *device = "default";
    
    // Opens a PCM
    if (snd_pcm_open(ppcmHandle, device, SND_PCM_STREAM_PLAYBACK, 0) < 0)
        printf("snd_pcm_open error\n");
}

unsigned long SetupPCM(snd_pcm_t* pcmHandle)
{
    snd_pcm_hw_params_t* hwParams;

    // Allocate an invalid snd_pcm_hw_params_t using standard malloc 
    if (snd_pcm_hw_params_malloc(&hwParams) < 0)
        printf("snd_pcm_hw_params_malloc error\n");

    // The configuration space will be filled with all possible ranges for the PCM device
    if (snd_pcm_hw_params_any(pcmHandle, hwParams) < 0)
        printf("snd_pcm_hw_params_any error\n");

    // Restrict a configuration space to contain only the interleaved access type 
	if (snd_pcm_hw_params_set_access(pcmHandle, hwParams, SND_PCM_ACCESS_RW_INTERLEAVED) < 0) 
        printf("snd_pcm_hw_params_set_access error\n");

    // Restrict a configuration space to contain only signed 16 bit little endian format 
	if (snd_pcm_hw_params_set_format(pcmHandle, hwParams, SND_PCM_FORMAT_S16_LE) < 0)
        printf("snd_pcm_hw_params_set_format error\n");

    // Restrict a configuration space to contain two channels, stereo 
	if (snd_pcm_hw_params_set_channels(pcmHandle, hwParams, 2) < 0)
        printf("snd_pcm_hw_params_set_channels error\n");

    // Restrict a configuration space to have a sample rate nearest to a 44100hZ 
    unsigned int rate = SAMPLE_RATE;
	if (snd_pcm_hw_params_set_rate_near(pcmHandle, hwParams, &rate, 0) < 0) 
        printf("snd_pcm_hw_params_set_rate_near error\n");

    // Install one PCM hardware configuration chosen from a configuration space
	if (snd_pcm_hw_params(pcmHandle, hwParams) < 0)
        printf("snd_pcm_hw_params error\n");

    // Extract period size from a configuration space
    unsigned long periodSize;
    if (snd_pcm_hw_params_get_period_size(hwParams, &periodSize, 0) < 0)
        printf("snd_pcm_hw_params_get_period_size error\n");

    // Prepare PCM for use 
    if (snd_pcm_prepare(pcmHandle) < 0)
        printf("snd_pcm_prepar error\n");

	printf("PCM state:\t%s\n", snd_pcm_state_name(snd_pcm_state(pcmHandle)));
    return periodSize;
} 

void FillTrackFile(struct TrackInfo trackArray[30], char* path, int* pArrayTotal)
{
    DIR*            dir;
    struct dirent*  ent;
    
    if (dir = opendir(path))
    {
        int index = 0;
        while (ent = readdir(dir)) 
        {
            if (strstr(ent->d_name, ".ogg"))   
                strcpy(trackArray[index++].FileName, ent->d_name);
        }
        closedir(dir);
        *pArrayTotal = index; 
    } 
}

void FillVorbisInfo(struct TrackInfo trackArray[30], char* path, int total)
{
    char fullPath[NAME_MAX];
    strcpy(fullPath, path);

    for (int i = 0; i < total; i++)
    {
        strcat(fullPath, trackArray[i].FileName);

        if (ov_fopen(fullPath, &trackArray[i].VorbisFile) < 0)
            printf("ov_fopen error\n");

        vorbis_comment* vc = trackArray[i].VorbisFile.vc;
        int numberOfComments = vc->comments;

        while (numberOfComments--)
        {
            if (strncmp("ARTIST=", vc->user_comments[numberOfComments], 7) == 0)
                strcpy(trackArray[i].Artist, vc->user_comments[numberOfComments] + 7);
            else if (strncmp("artist=", vc->user_comments[numberOfComments], 7) == 0)
                strcpy(trackArray[i].Artist, vc->user_comments[numberOfComments] + 7);
            else if (strncmp("TITLE=", vc->user_comments[numberOfComments], 6) == 0)
                strcpy(trackArray[i].Title, vc->user_comments[numberOfComments] + 6);
            else if (strncmp("title=", vc->user_comments[numberOfComments], 6) == 0)
                strcpy(trackArray[i].Title, vc->user_comments[numberOfComments] + 6);
            else if (strncmp("TRACKNUMBER=", vc->user_comments[numberOfComments], 12) == 0)
                trackArray[i].Number = atoi(vc->user_comments[numberOfComments] + 12);
            else if (strncmp("tracknumber=", vc->user_comments[numberOfComments], 12) == 0)
                trackArray[i].Number = atoi(vc->user_comments[numberOfComments] + 12);
            else if (strncmp("ALBUM=", vc->user_comments[numberOfComments], 6) == 0)
                strcpy(trackArray[i].Album, vc->user_comments[numberOfComments] + 6);
            else if (strncmp("album=", vc->user_comments[numberOfComments], 6) == 0)
                strcpy(trackArray[i].Album, vc->user_comments[numberOfComments] + 6);
        }

        // Clean the filename off the path
        char* pSlash = strrchr(fullPath,'/');
        
        if (pSlash)
        {
            pSlash++;
            *pSlash = 0;
        }
    }
}

void BubbleSortTracks(struct TrackInfo trackArray[30], int total)
{
    bool bSwitches = true;
    struct TrackInfo holdingPen;

    while (bSwitches)
    {
        bSwitches = false;

        for (int i = 0; i < (total - 1); i++)
        {
            if (trackArray[i].Number > trackArray[i+1].Number)
            {
                holdingPen = trackArray[i+1];
                trackArray[i+1] = trackArray[i];
                trackArray[i] = holdingPen;
                bSwitches = true;
            } 
        }    
    }
}

void GetPathFromArtist(char path[PATH_MAX], char* artist)
{
    char QueryString[PATH_MAX] = {"SELECT Path FROM Albums WHERE Artist = \""};

    strcat(QueryString, artist);
    strcat(QueryString, "\"");

    MYSQL* pConnection = mysql_init(NULL);

    if (!mysql_real_connect(pConnection, "localhost" , "root" , "root", "Albums", 0 , NULL, 0))
    {
        printf("%s\n", mysql_error(pConnection));
        mysql_close(pConnection);
    }

    if (mysql_query(pConnection, QueryString))
    {
        printf("%s\n", mysql_error(pConnection));
        mysql_close(pConnection);
    }

    MYSQL_RES* result = mysql_store_result(pConnection);
  
    if (!result) 
    {
        printf("%s\n", mysql_error(pConnection));
        mysql_close(pConnection);
    }

    MYSQL_ROW row;
    
    while ((row = mysql_fetch_row(result))) 
    { 
        strcpy(path, *row);
        strcat(path, "/");
    }

    mysql_free_result(result);
    mysql_close(pConnection);
}