/*
$Id: pthread_create.c 5 2007-03-31 15:04:06Z Makhtar $
Experiment with threads
*/

#include "malib.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printxs(void *unused) {
  for (;;) /* forever */
  {
    fputc('x', stderr);
    pausethis(1); /* pause for a little while */
  }
  /* should not get here */
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, &printxs, NULL);

  for (;;) {
    fputc('o', stderr);
    pausethis(1); /* pause for a while */
  }

  return EXIT_SUCCESS;
}
