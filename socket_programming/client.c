#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define MAX_LEN_MESSAGE 65535

typedef struct sockaddr_in sockaddr;

int 
main()
{
    // create socket fd
    int sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (sockfd == -1){
        perror("socket");
        return 1;
    }

    // connect 
    sockaddr server_addr;                       // server addr
    server_addr.sin_family = AF_LOCAL;
    server_addr.sin_port = htons(PORT);
    // server_addr.sin_addr
    // server_addr.sin_zero
    
    // inet_net_pton()

    // ??? for the second parameter?? why?
    // I can't understand here the second parameter of connect() func.???
    int client_fd = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (client_fd == -1){
        perror("connect");
        return 1;
    }

    // write message
    char *message = "hello, this is client.";
    int send_num = send(client_fd, message, strnlen(message, MAX_LEN_MESSAGE), 0); // what is the last parameter?
    if (send_num == -1){
        perror("send");
        return 1;
    }

    // read message
    char readbuff[MAX_LEN_MESSAGE + 1];
    int readbuff_len = 0;
    int read_num = read(client_fd, readbuff, readbuff_len);
    readbuff[MAX_LEN_MESSAGE] = '\0';
    
    // output read message
    if (read_num > 0){
        printf("%s\n", readbuff);
    }

    close(client_fd);
    return 0;
}
