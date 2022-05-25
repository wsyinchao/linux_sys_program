#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
// #include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>

#define PORT 8080

typedef struct sockaddr_in sockaddr;

int 
main()
{
    //create socket fd
    int sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);

    //bind
    sockaddr addr_server;
    addr_server.sin_family = AF_LOCAL;
    addr_server.sin_addr.s_addr = INADDR_ANY;
    addr_server.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&addr_server, sizeof(addr_server))){
        perror("bind");
        return 1;
    }

    return 0;
}
