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
// gcc -W -o MusicPlayer Main.c PCM.c Vorbis.c WatchDog.c FileManager.c -lasound -lvorbisfile -lmysqlclient
//
// This file will use the alsa lib to set up the pulse-code modulation interface 
// (PCM) to play output and use the vorbis lib to read in a .ogg file and pass
// it to the PCM
///////////////////////////////////////////////////////////////////////
#include <dirent.h>
#include <stdbool.h>
#include "MusicPlayer.h"

#include <unistd.h>

int main(int argc, char *argv[])
{
    char PlayPath[PATH_MAX];
    memset(PlayPath, 0, PATH_MAX);

    printf("%s %d\n", argv[1], argc);

    if (argc == 2)
        strcpy(PlayPath, argv[1]);
    else
        PatWatchDog(PlayPath);

    PlayAlbum(PlayPath);

    while(true)
    {
        PatWatchDog(PlayPath);
        PlayAlbum(PlayPath);
    }

    return 1;
}

void PlayAlbum(char* PlayPath)
{
    HexDump ("PlayPath", PlayPath, MAX_ALBUM_TRACKS);
    struct TrackInfo trackArray[MAX_ALBUM_TRACKS]; // Allocate track info
    memset(trackArray, 0, MAX_ALBUM_TRACKS * sizeof(struct TrackInfo));

    int ArrayTotal = 0;
    FillTrackFile(trackArray, PlayPath, &ArrayTotal);
    PrintArray(trackArray);
    FillVorbisInfo(trackArray, PlayPath, ArrayTotal);
    PrintArray(trackArray);
    BubbleSortTracks(trackArray, ArrayTotal);
    PrintArray(trackArray);

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
        char Stop[NAME_MAX];
        GetStop(Stop);
        if (strcmp(Stop,"true") == 0)
            i = ArrayTotal;
    }
    snd_pcm_close(pcmHandle);   // close PCM handle 
}

void FillTrackFile(struct TrackInfo trackArray[MAX_ALBUM_TRACKS], const char path[PATH_MAX], int* pArrayTotal)
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

void BubbleSortTracks(struct TrackInfo trackArray[MAX_ALBUM_TRACKS], int total)
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

void HexDump (const char * desc, const void * addr, const int len) 
{
    #ifdef DEBUG_OUT
    int i;
    unsigned char buff[17];
    const unsigned char * pc = (const unsigned char *)addr;

    // Output description if given.
    if (desc != NULL)
        printf ("%s:\n", desc);

    // Length checks.
    if (len == 0) {
        printf("  ZERO LENGTH\n");
        return;
    }
    else if (len < 0) {
        printf("  NEGATIVE LENGTH: %d\n", len);
        return;
    }

    // Process every byte in the data.
    for (i = 0; i < len; i++) 
    {
        // Multiple of 16 means new line (with line offset).
        if ((i % 16) == 0) 
        {
            // Don't print ASCII buffer for the "zeroth" line.
            if (i != 0)
                printf ("  %s\n", buff);

            // Output the offset.

            printf ("  %04x ", i);
        }

        // Now the hex code for the specific character.
        printf (" %02x", pc[i]);

        // And buffer a printable ASCII character for later.

        if ((pc[i] < 0x20) || (pc[i] > 0x7e)) // isprint() may be better.
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }

    // And print the final ASCII buffer.
    printf ("  %s\n", buff);
    #endif
}

void PrintArray(struct TrackInfo trackArray[MAX_ALBUM_TRACKS])
{
    #ifdef DEBUG_OUT
    for(int i = 0; i < MAX_ALBUM_TRACKS; i++)
    {
        printf("%s\n", trackArray[i].FileName);
    }
    #endif
}
