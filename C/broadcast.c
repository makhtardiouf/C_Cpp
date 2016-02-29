/*
   $Id: broadcast.c 5 2007-03-31 15:04:06Z Makhtar $
   Sends a broadcast message
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malib.h"

int main(int argc,char **argv)
{
    SOCKET s;
    struct sockaddr_in broadcast_addr;
    int optval;
    int optlen;
    s = INVALID_SOCKET;
    CLEAR_ADDR(&broadcast_addr);

    if (argc != 3) {
        printf("usage: %s message port\n", argv[0]);
        return SUCCESS;
    }
    sockInit();
    /* specify broadcast address and port, byte order conversion*/
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons((unsigned short) atoi(argv[2]));
    broadcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST); /* send to all */

    /* create socket in the internet namespace */
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s == INVALID_SOCKET) {
        printf("Can't create socket\n");
        sockEnd();
        return SUCCESS;
    }
    optval = 1;
    optlen = sizeof(int);
    if (setsockopt(s, SOL_SOCKET,SO_BROADCAST, (char *) &optval,optlen)) {
        printf("Cannot create a BROADCAST socket\n");
        sockEnd();
        return FAILURE;
    }
    /* send data */
    if (sendto(s, argv[1], strlen(argv[1]), 0, (struct sockaddr *)
               &broadcast_addr, sizeof(struct sockaddr_in)) == -1) {
        printf("Can't send message\n");
        sockEnd();
        return FAILURE;
    }
    /* close the channel */
    if (closesocket(s)) {
        printf("Error on closing socket\n");
        sockEnd();
        return FAILURE;
    }
    sockEnd();
    return SUCCESS;
}
