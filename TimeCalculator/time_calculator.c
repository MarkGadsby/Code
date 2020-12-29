#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
    char input_time[FILENAME_MAX] = {"0:00"};

    char* separator = strstr(input_time, ":");
    *separator = 0;

    int time_mark = atoi(input_time) * 60 + atoi(separator + 1);

    while (time_mark < 3600)
    {
        printf("\n\nPlease enter track time (m:s):\n");
        scanf("%s", input_time);

        separator = strstr(input_time, ":");
        *separator = 0;

        int track_seconds = atoi(input_time) * 60 + atoi(separator + 1);

        time_mark = time_mark + track_seconds;

        printf("\n\nCurrent time mark is : %d:%02d\n", time_mark / 60, time_mark % 60);
    } 
    return 0;
}