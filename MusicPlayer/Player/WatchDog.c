#include "MusicPlayer.h"
#include <sys/inotify.h>

void PatWatchDog(char TitleToPlay[PATH_MAX])
{
    char buffer[PATH_MAX];
    struct inotify_event* pEvent;

    int inotifyFd = inotify_init();

    if (inotifyFd == -1)
        printf("inotify_init");

    int wd = inotify_add_watch(inotifyFd, "NowPlaying", IN_CLOSE_WRITE);

    printf("The watchdog is watching\n");

    ssize_t numRead = read(inotifyFd, buffer, 256);

    if (numRead < 0)
        printf("read error");
    else
    {
        pEvent = (struct inotify_event*) buffer;

        if (pEvent->mask & IN_CLOSE_WRITE)
        {
            GetPlayPath(TitleToPlay);
        }
    }   
    inotify_rm_watch(inotifyFd, wd);
    close(inotifyFd);
}