///////////////////////////////////////////////////////////////////////////////
// Simple proggram that takes the output from running;
// 
// >find ~/Music -type d -links 2 > ~/Code/MusicPlayer/PathParser/paths.txt
//
// and reads in each bare path and picks out the artist and title of the album.
// Then writes it back into the parsed.txt file as 'path' - tab - 'tier' - tab -
// 'aritst' - tab - 'title' - new line. This format matches the Album table in the 
// Album database so you can use this SQL to load the data in:
//
// mysql > LOAD DATA LOCAL INFILE '~/Code/MusicPlayer/PathParser/parsed.txt' INTO TABLE Albums;
//
// To Build:
// >g++ -Wall -o PathParser main.c
//
///////////////////////////////////////////////////////////////////////////////
#include <linux/limits.h>
#include <stdio.h>
#include <string.h>

const int FIRST_FOLDER = 17;     //  forward slash after the base folder; "/home/mark/Music/"

int main()
{
    FILE* paths = fopen("paths.txt", "r");
    FILE* parsed = fopen("parsed.txt", "w");

    if (paths == NULL)
    {
        printf("Couldn't find the paths.txt file on your disk\n");
        return 0;
    }

    char path[PATH_MAX];
    int secondindex = 0;

    while (!feof(paths))
    {
        fgets(path, PATH_MAX, paths);

        secondindex = 0;

        char artist[NAME_MAX];
        memset(artist, 0, NAME_MAX);
        char title[NAME_MAX];
        memset(title, 0, NAME_MAX);

        char* pSecondFolder = strchr(path + FIRST_FOLDER, '/');

        if (pSecondFolder)
            secondindex = pSecondFolder - path;

        if (secondindex)
        {
            strncpy(artist, path + FIRST_FOLDER, secondindex - FIRST_FOLDER);
            strcpy(title, path + secondindex + 1);
        }
        else // Put the same string in both artist and title if no second folder exists
        {
            strcpy(artist, path + FIRST_FOLDER);

            // lose the trailing new line from 'artist' which was copied from the original 'path'
            int len = strlen(artist);
            if (artist[len - 1] == '\n')
                artist[len - 1] = 0;

            strcpy(title, path + FIRST_FOLDER);
        }

        // the new line has been copied to the end of 'title' by now so lose it from the original 'path'
        int len = strlen(path);
        if (path[len - 1] == '\n')
            path[len - 1] = 0;

        strcat(path, "\t0\t");
        strcat(path, artist);
        strcat(path, "\t");
        strcat(path, title);

        fputs(path, parsed);
    } 
    fclose(paths);
    fclose(parsed);
    return 0;
}
