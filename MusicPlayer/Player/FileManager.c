#include "MusicPlayer.h"

void GetFileEntry(char Value[], char* pEntry, int nEntryID)
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

void GetTitleToPlay(char TitleToPlay[])
{
    GetFileEntry(TitleToPlay, "Title=", 6);
}

void GetStop(char Stop[])
{
    GetFileEntry(Stop, "Stop=", 5);
}

