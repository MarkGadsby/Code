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
void FillTrackFile(struct TrackInfo trackArray[30], char* path, int* pArrayTotal);
void FillVorbisInfo(struct TrackInfo trackArray[30], char* path, int total);
void BubbleSortTracks(struct TrackInfo trackArray[30], int total);