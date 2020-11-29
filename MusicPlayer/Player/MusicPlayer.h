#ifndef MP_H
#define MP_H

#define MAX_ALBUM_TRACKS 64
#define DEBUG_OUT

#include <alsa/asoundlib.h>
#include <vorbis/vorbisfile.h>
#include <linux/limits.h>

struct TrackInfo
{
    char FileName[NAME_MAX];
    char Artist[NAME_MAX];
    char Title[NAME_MAX];
    char Album[NAME_MAX];
    OggVorbis_File VorbisFile;
    int Number;
};

// Musicplayer definition file
void OpenPCM(snd_pcm_t** ppcmHandle);
unsigned long SetupPCM(snd_pcm_t* pcmHandle);
void FillTrackFile(struct TrackInfo trackArray[MAX_ALBUM_TRACKS], const char* path, int* pArrayTotal);
void FillVorbisInfo(struct TrackInfo trackArray[MAX_ALBUM_TRACKS], char* path, int total);
void BubbleSortTracks(struct TrackInfo trackArray[MAX_ALBUM_TRACKS], int total);
void PatWatchDog(char* Path);
void PlayAlbum(char* Path);
void GetFileEntry(char* filename, char* pEntry, int nEntryID, char* Value);
void GetPlayPath(char* Path);
void GetStop(char* Stop);
void HexDump (const char* desc, const void* addr, const int len); 
void PrintArray(struct TrackInfo trackArray[MAX_ALBUM_TRACKS]);

#endif

