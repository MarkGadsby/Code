#include "MusicPlayer.h"

void GetFileEntry(char* filename, char* pEntry, int nEntryID, char* Value)
{
    FILE* pFile = fopen(filename, "r");
    char FileString[PATH_MAX];

    while (!feof(pFile))
    {
        fgets(FileString, PATH_MAX, pFile);

        if (strstr(FileString, pEntry))
        {
            strcpy(Value, FileString + nEntryID);                
            break;
        }        
    }   
    fclose(pFile);
}

void GetPlayPath(char* Path)
{
    GetFileEntry("NowPlaying", "AlbumPath=", 10, Path);
}

void GetStop(char* Stop)
{
    GetFileEntry("MusicPlayer.config", "Stop=", 5, Stop);

    char* pPos;
    pPos = strchr(Stop, '\n');
    if (pPos)
        *pPos = '\0';
}

