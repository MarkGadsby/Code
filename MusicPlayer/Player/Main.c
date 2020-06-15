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
// gcc -W -o MusicPlayer Main.c MySQL.c PCM.c Vorbis.c WatchDog.c FileManager.c -lasound -lvorbisfile -lmysqlclient
//
// This file will use the alsa lib to set up the pulse-code modulation interface 
// (PCM) to play output and use the vorbis lib to read in a .ogg file and pass
// it to the PCM
///////////////////////////////////////////////////////////////////////
#include <dirent.h>
#include <stdbool.h>
#include "MusicPlayer.h"

const int MAX_ALBUM_TRACKS = 64;

int main(int argc, char *argv[])
{
    char TitleToPlay[PATH_MAX];
    if (argc == 2)
        strcpy(TitleToPlay, argv[1]);
    else
        PatWatchDog(TitleToPlay);

    char PlayPath[PATH_MAX];

    GetPathFromTitle(PlayPath, TitleToPlay);

    struct TrackInfo trackArray[MAX_ALBUM_TRACKS]; // Allocate track info
    memset(trackArray, 0, MAX_ALBUM_TRACKS * sizeof(struct TrackInfo));

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

        // Check for stop request
        char Status[NAME_MAX];
        GetNextStatus(Status);
        if (strcmp(Status,"StopAfterTrack"))
            i = ArrayTotal;
    }
    snd_pcm_close(pcmHandle);   // close PCM handle 
    return 1;
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