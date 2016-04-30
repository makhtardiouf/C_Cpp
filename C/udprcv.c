/*
   $Id: udprcv.c 8 2007-04-30 22:25:20Z Makhtar $
   Receives and prints a message
*/

#include "malib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 128

int main(int argc, char **argv) {
  SOCKET s;
  struct hostent *hp;
  struct sockaddr_in any_addr;
  char remotename[128];
  char remoteaddr[128];
  char buffer[BUFLEN];
  int rec;
  struct sockaddr_in remote_addr;
  int addrlen;

  s = INVALID_SOCKET;
  hp = NULL;
  CLEAR_ADDR(&any_addr);
  addrlen = sizeof(struct sockaddr_in);

  if (argc != 2) {
    printf("usage: %s port\n", argv[0]);
    return 0;
  }

  sockInit();

  /* specifies host and port */
  any_addr.sin_family = AF_INET;
  any_addr.sin_port = htons((unsigned short)atoi(argv[1]));

  /* accepts connections from any client */
  any_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  /* creates socket */
  s = socket(AF_INET, SOCK_DGRAM, 0);

  if (s == INVALID_SOCKET) {
    printf("Can't create socket\n");
    sockEnd();
    return 2;
  }

  /* links socket to address and port */
  if (bind(s, (struct sockaddr *)&any_addr, sizeof(struct sockaddr_in))) {
    printf("Can't bind socket to address\n");
    sockEnd();
    return 3;
  }

  rec =
      recvfrom(s, buffer, BUFLEN, 0, (struct sockaddr *)&remote_addr, &addrlen);
  if (rec == -1) {
    printf("Can't receive messages\n");
    sockEnd();
    return 4;
  }

  buffer[rec] = 0x00;
  sockName(&remote_addr, remotename, remoteaddr);

  /* output received data  with client information */
  printf("Message received from host: %s ( address: %s )\n%s\n", remotename,
         remoteaddr, buffer);

  if (closesocket(s)) {
    perror("closesocket");
    return 5;
  }

  sockEnd();
  return EXIT_SUCCESS;
}
