/*
   $Id: udpsend.c 5 2007-03-31 15:04:06Z Makhtar $
   Sends a message to a remote host
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emdutils.h"


int main(int argc,char **argv)
{
    SOCKET s;
    struct hostent *hp, *lp;
    struct sockaddr_in remote_addr, local_addr;

    s = INVALID_SOCKET;
    hp = NULL;
    lp = NULL;
    CLEAR_ADDR(&remote_addr);

    if (argc != 4) {
        printf("usage: %s message hostname port\n",argv[0]);
        return 0;
    }

    sockInit();

    /* find host */
    hp = gethostbyname(argv[2]);
    lp = gethostbyname("localhost");
    if (hp == NULL) {
        printf("Cannot find host %s\n",argv[2]);
        sockEnd();
        return 1;
    }

    /* specify host and port */
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons((unsigned short) atoi(argv[3]));
    remote_addr.sin_addr.s_addr = ((struct in_addr *)(hp->h_addr))->s_addr;

    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons((unsigned short) atoi(argv[3]));
    local_addr.sin_addr.s_addr = ((struct in_addr *)(hp->h_addr))->s_addr;


    /* create socket */
    s = socket(AF_INET,SOCK_DGRAM,0);

    if (s == INVALID_SOCKET) {
        printf("Can't create socket\n");
        sockEnd();
        return 2;
    }

    /* link socket to address and port */
    /*if(bind(s,(struct sockaddr *) &local_addr, sizeof(struct sockaddr_in))) {
          printf("Can't bind socket to address\n");  
          sockEnd();   
          return 3;  
    } */

    /* send data */
    if (sendto(s, argv[1], strlen(argv[1]), 0, (struct sockaddr *)
               &remote_addr, sizeof(struct sockaddr_in))==-1) {
        printf("Can't send message\n");
        sockEnd();
        return 3;
    }

    /* close the channel */
    if (closesocket(s)) {
        printf("Error on closing socket\n");
        return 4;
    }

    return EXIT_SUCCESS;
}
