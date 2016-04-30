/*
   $Id: findhost.c 18 2008-07-06 09:18:48Z Makhtar $
   Retrieves information about a host given its name or address
*/
#define _GNU_SOURCE
#include "malib.h"
#include "socket.h"
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum { HNAME_SIZE = 128 };

int main(int argc, char **argv) {
  char myname[HNAME_SIZE];
  char **hname = NULL;
  char **haddr = NULL;
  struct hostent *host = NULL;
  char d_address[4];
  char fun[] = "gethostbyaddr()";
  const void *CP = (const void *)argv[1];

  if (init_socket()) {
    perror("sockInit()");
    return EXIT_FAILURE;
  }

  if (argc < 2) {
    if (gethostname(myname, (size_t)HNAME_SIZE)) {
      perror("gethostname()");
      end_socket();
      return EXIT_FAILURE;
    }

    printf("Hello, my name is: %s\n", myname);
    return EXIT_SUCCESS;
  }

  /*      if(inetAddrConvert(argv[1], d_address))  */
  if (inet_ntop(AF_INET, CP, d_address, (size_t)sizeof(d_address)) == NULL) {
    host = gethostbyname(argv[1]);
    strcpy(fun, "gethostbyname()");
  } else {
    host = gethostbyaddr(d_address, sizeof(d_address), AF_INET);
    strcpy(fun, "gethostbyaddr()");
  }

  if (host == '\0') {
    perror("gethostbyname()");
    end_socket();
    return EXIT_FAILURE;
  }
  printf("Information provided by %s:\n", fun);
  printf("\tHost name: %s\n", host->h_name);
  printf("\tHost address: %d.%d.%d.%d\n", host->h_addr_list[0][0],
         host->h_addr_list[0][1], host->h_addr_list[0][2],
         host->h_addr_list[0][3]);

  hname = host->h_aliases;
  if (*hname != NULL) {
    printf("\tHost alternate names: "); /* (hname[1] == '\0') ? ":" : "s:" ); */
    while (*hname != '\0') {
      printf("%s ", *hname);
      ++hname;
    }
  }

  haddr = host->h_addr_list;
  if (*haddr != NULL) {
    printf("\n\tHost alternate address(es): "); /* (haddr[1] == '\0') ? ":" :
                                                   "es:" );*/

    while (*haddr != '\0') {
      printf("%d.%d.%d.%d ", *haddr[0], *haddr[1], *haddr[2], *haddr[3]);
      ++haddr;
    }
  }

  printf("\n");

  end_socket();
  return EXIT_SUCCESS;
}
