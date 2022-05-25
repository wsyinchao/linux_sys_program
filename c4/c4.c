#include <sys/epoll.h>
#include <stdio.h>
#include <unistd.h>

int
main()
{
    int epfd = epoll_create1(EPOLL_CLOEXEC);
    if (epfd < 0){
        perror("epoll_create1");
    }
    close(epfd);

    return 0;
}
