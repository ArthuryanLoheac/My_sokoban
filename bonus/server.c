#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "sokoban.h"

int main (int argc, char **argv)
{
    //CREATION SERVEUR :
    int socket_serv = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrserv;
    addrserv.sin_addr.s_addr = inet_addr("127.0.0.1"); //10.29.125.253
    addrserv.sin_family = AF_INET;
    addrserv.sin_port = htons(30000);

    //CONNECTION SERVEUR
    bind(socket_serv, (const struct sockaddr *)&addrserv, sizeof(addrserv));

    //ATTENTE CONNECTION DES CLIENTS
    listen(socket_serv, 2);
    printf("ATTENTE DE CONNECTION DU JOUEUR 2 ...\n");

    //CONNECTION CLIENT
    struct sockaddr_in addr_client;
    socklen_t csize = sizeof(addr_client);
    int socket_client = accept(socket_serv, (struct sockaddr *)&addr_client, &csize);

    //ENVOIE DONNES
    if (first_player(argc, argv, socket_client) != 0) {
        printf("ERREUR\n");
        return 84;
    }

    //FERMETURE SERVEUR
    close(socket_serv);
    return 0;
}
