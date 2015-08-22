
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emdutils.h"
#include "socket.h"


int main(int argc, char **argv)
{
    SOCKET s;
    struct hostent *hp;
    struct sockaddr_in remote_addr;

    s = INVALID_SOCKET;
    hp = NULL;
    CLEAR_ADDR(&remote_addr);

    if (argc != 4) {
        fprintf(stderr, "usage: %s message hostname port\n", argv[0]);
        return 0;
    }

    sockInit();

    /* find host */
    hp = gethostbyname(argv[2]);
    if (hp == NULL) {
        fprintf(stderr, "Cannot find host %s\n", argv[2]);
        sockEnd();
        return 1;
    }

    /* specify host and port */
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons((unsigned short) atoi(argv[3]));
    remote_addr.sin_addr.s_addr = ((struct in_addr *)(hp->h_addr))->s_addr;

    /* create socket */
    s = socket(AF_INET, SOCK_STREAM, 0);

    if (s == INVALID_SOCKET) {
        fprintf(stderr, "Can't create socket\n");
        sockEnd();
        return 2;
    }

    /* send data */
    connect(s, (struct sockaddr *) &remote_addr, sizeof(struct sockaddr_in));
    if (send(s, argv[1], strlen(argv[1]), 0) == -1) {
        fprintf(stderr, "Can't send message\n");
        sockEnd();
        return 3;
    }

    /* close the channel */
    if (closesocket(s)) {
        fprintf(stderr, "Error on closing socket\n");
        return 4;
    }

    return 0;
}
