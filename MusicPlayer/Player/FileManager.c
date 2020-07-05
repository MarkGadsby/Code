#include "MusicPlayer.h"

void GetFileEntry(char* Value, char* pEntry, int nEntryID)
{
    FILE* pFile = fopen("playlist", "r");
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
    GetFileEntry(Path, "Title=", 6);

    char* pPos;
    pPos = strchr(Path, '\r');
    if (pPos)
        *pPos = '\0';
}

void GetStop(char Stop[])
{
    GetFileEntry(Stop, "Stop=", 5);

    char* pPos;
    pPos = strchr(Stop, '\r');
    if (pPos)
        *pPos = '\0';
}

