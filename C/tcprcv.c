/*
$Id: tcprcv.c 8 2007-04-30 22:25:20Z Makhtar $

*/

#include "sockLib.h"
#include <stdio.h>

#define BUFLEN 128

/* Handle the communication with the client */
void serverThread(SOCKET ss) {

  pid_t pid;
  char remotename[128];
  char remoteaddr[128];
  char buffer[BUFLEN];
  int rec;
  struct sockaddr_in remote_addr;
  int addrlen;

  addrlen = sizeof(struct sockaddr_in);
  pid = getpid();
  /* waits for incoming data */
  rec = recv(ss, buffer, BUFLEN, 0);
  if (rec == -1) {
    printf("Can't receive messages\n");
    sockEnd();
    return;
  }

  buffer[rec] = 0x00;

  /* finds the name of client */
  CLEAR_ADDR(&remote_addr);
  getpeername(ss, (struct sockaddr *)&remote_addr, &addrlen);
  sockName(&remote_addr, remotename, remoteaddr);

  /* output received data */
  printf("Message received from host: %s ( address: %s )\n%s\n", remotename,
         remoteaddr, buffer);

  /* close the channel */
  if (closesocket(ss))
    printf("Error on closing socket\n");
}

int main(int argc, char **argv) {
  SOCKET s;
  struct hostent *hp;
  struct sockaddr_in any_addr;
  int addrlen;
  SOCKET ss;

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
  s = socket(AF_INET, SOCK_STREAM, 0);

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

  /* listens on port; maximum 5 requests pending */
  listen(s, 5);

  /* when someone connects creates a new socket for data exchange */
  ss = accept(s, (struct sockaddr *)&any_addr, &addrlen);

  if (ss == INVALID_SOCKET) {
    perror("accept");
    return 4;
  }

  serverThread(ss);

  if (closesocket(s)) {
    perror("closesocket");
    return 5;
  }

  sockEnd();
  return 0;
}
