#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <netinet/in.h>
#include <sys/select.h>

typedef struct s_client
{
    int id;
    char msg[10000];
}   t_client;

t_client clients[1024];
fd_set read_set, write_set, current;
int maxfd = 0, cli_id = 0;
char send_buffer[10000], recv_buffer[10000];

void printError(const char *msg)
{
    if (msg)
        write(2, msg, strlen(msg));
    else
        write(2, "Fatal error\n", 12);
    exit(1);
}

void broadcast_message(int sender)
{
    for (int fd = 0; fd <= maxfd; fd++)
        if (FD_ISSET(fd, &write_set) && fd != sender)
            if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
                printError(NULL);
}

void process_message(int fd)
{
    int i = 0;
    while (i < strlen(recv_buffer))
    {
        int j = i;
        while (recv_buffer[j] != '\n' && recv_buffer[j] != '\0')
            j++;
        if (recv_buffer[j] == '\n')
        {
            recv_buffer[j] = '\0';
            sprintf(send_buffer, "client %d: %s\n", clients[fd].id, &recv_buffer[i]);
            broadcast_message(fd);
            i = j + 1;
        }
        else
            break ;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        printError("Wrong number of arguments\n");
    
    struct sockaddr_in serveraddr;
    socklen_t len = sizeof(serveraddr);
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1)
        printError(NULL);
    maxfd = serverfd;

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    serveraddr.sin_port = htons(atoi(argv[1]));
    if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1)
        printError(NULL);
    if (listen(serverfd, 100) == -1)
        printError(NULL);
    FD_ZERO(&current);
    FD_SET(serverfd, &current);
    memset(clients, 0, sizeof(clients));

    while (1)
    {
        read_set = write_set = current;
        if (select(maxfd + 1, &read_set, &write_set, NULL, NULL) == -1)
            continue ;
        
        for (int fd = 0; fd <= maxfd; fd++)
        {
            if (FD_ISSET(fd, &read_set))
            {
                if (fd == serverfd)
                {
                    int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len);
                    if (clientfd == -1)
                        continue ;
                    if (clientfd > maxfd)
                        maxfd = clientfd;
                    clients[clientfd].id = cli_id++;
                    FD_SET(clientfd, &current);
                    sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id);
                    broadcast_message(clientfd);
                }
                else
                {
                    int bytes = recv(fd, recv_buffer, sizeof(recv_buffer) - 1, 0);
                    if (bytes <= 0)
                    {
                        sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
                        broadcast_message(fd);
                        FD_CLR(fd, &current);
                        close(fd);
                        clients[fd].msg[0] = '\0';
                    }
                    else
                    {
                        recv_buffer[bytes] = '\0';
                        process_message(fd);
                    }
                }
            }
        }
    }
    return (0);
}