#include "MusicPlayer.h"

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