#include "MusicPlayer.h"
#include <sys/inotify.h>

void PatWatchDog(char TitleToPlay[PATH_MAX])
{
    char buffer[PATH_MAX];
    struct inotify_event* pEvent;

    int inotifyFd = inotify_init();

    if (inotifyFd == -1)
        printf("inotify_init");

    int wd = inotify_add_watch(inotifyFd, "playlist", IN_CLOSE_WRITE);

    printf("The watchdog is watching\n");

    ssize_t numRead = read(inotifyFd, buffer, 256);

    if (numRead < 0)
        printf("read error");
    else
    {
        printf("Got Event\n");

        pEvent = (struct inotify_event*) buffer;

        if (pEvent->mask & IN_CLOSE_WRITE)
        {
            FILE* pFile = fopen("playlist", "r");
            fgets(TitleToPlay, PATH_MAX, pFile);
            fclose(pFile);

            int len = strlen(TitleToPlay);
            if (TitleToPlay[len - 1] == '\n')
                TitleToPlay[len - 1] = 0;
        }
    }   
    inotify_rm_watch(inotifyFd, wd);
    close(inotifyFd);
}