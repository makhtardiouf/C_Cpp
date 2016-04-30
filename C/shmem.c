/*
$Id: shmem.c 8 2007-04-30 22:25:20Z Makhtar $
Experiment with Inter Process Communication(IPC)
See "Advanced Linux Programming"
*/

/* Get access to the IPC family of functions */
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(void) {
  int segid;
  char *shm;
  struct shmid_ds shm_buf;
  int seg_sz;
  const int shseg_sz = 0x6400; /* 25600 in decimal */

  /* Allocate a shared memory segment */
  segid =
      shmget(IPC_PRIVATE, shseg_sz, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

  /* Attach */
  shm = (char *)shmat(segid, 0, 0);
  printf("shared memory attached at address %p\n", shm);

  /* get segment size */
  shmctl(segid, IPC_STAT, &shm_buf);
  seg_sz = shm_buf.shm_segsz;
  printf("segment size: %d\n", seg_sz);

  /* Write a string to the shared memory segment. */
  sprintf(shm, "Hello, shared memory world!");

  /* Detach */
  shmdt(shm);

  /* Reattach mem at a different address. */
  shm = (char *)shmat(segid, (void *)0x5000000, 0);
  printf("shared memory reattached at address %p\n", shm);

  /* Print out the string from mem */
  printf("%s\n", shm);

  shmdt(shm);

  /* Deallocate */
  shmctl(segid, IPC_RMID, 0);

  return EXIT_SUCCESS;
}
