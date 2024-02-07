#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include "sokoban.h"
#include <ncurses.h>

int main(void)
{
    //CREER CLIENT
    int socket_client = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrclient;
    addrclient.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrclient.sin_family = AF_INET;
    addrclient.sin_port = htons(30000);

    //CONNECTE CLIENT
    connect(socket_client, (const struct sockaddr *)&addrclient, sizeof(addrclient));

    //RECEVOIR DONNEES
    player_two(socket_client);

    close(socket_client);
    return 0;
}