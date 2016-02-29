/*
   $Id: sockbind.c 5 2007-03-31 15:04:06Z Makhtar $
Experiment with sockects
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malib.h"

int main(int argc, char **argv)
{
    struct hostent *hp;
    struct sockaddr_in hostaddr_in;
    SOCKET s;

    if (argc < 4 || argc > 4) {
        puts("usage: sockbind hostname port type");
        return EXIT_SUCCESS;
    }

    memset(&hostaddr_in, 0, sizeof(struct sockaddr_in));
    hp = NULL;
    s = INVALID_SOCKET;

    if (sockInit()) {
        perror("sockInit");
        return EXIT_FAILURE;
    }

    hp = gethostbyname (argv[1]);

    if (hp == NULL) {
        perror("gethostbyname");
        sockEnd();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[3],"udp") == 0)
        s = socket(AF_INET, SOCK_DGRAM, 0);
    else
        if (strcmp(argv[3],"tcp") == 0)
            s = socket(AF_INET, SOCK_STREAM, 0);
        else {
            printf("Socket type not supported\n");
            sockEnd();
            return EXIT_FAILURE;
        }

    if (s == INVALID_SOCKET) {
        perror("socket");
        sockEnd();
        return EXIT_FAILURE;
    }

    /* fill the struct sockaddr_in */
    hostaddr_in.sin_family = AF_INET;
    hostaddr_in.sin_addr.s_addr = ((struct in_addr *)(hp->h_addr))->s_addr;
    /* byte order conversion for the port number */
    hostaddr_in.sin_port = htons((unsigned short) atoi(argv[2]));

    if ( bind(s, (struct sockaddr *) &hostaddr_in, sizeof(struct sockaddr_in)) ) {
        perror("bind");
        sockEnd();
        return EXIT_FAILURE;
    }

    printf("Socket %d succesfully created\n", s);
    closesocket(s);
    sockEnd();
    return EXIT_SUCCESS;
}
