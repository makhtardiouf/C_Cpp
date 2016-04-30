/*
$Id: temp_file.c 5 2007-03-31 15:04:06Z Makhtar $
Create a temporary file
*/

#include <stdlib.h>
#include <unistd.h>

/* A HANDLE for a temporary file created with write_temp_file. In
this implementation, it’s just a file descriptor. */
typedef int HANDLE;

char temp_filename[] = "/tmp/test_temp_file.XXXXXX";

HANDLE write_temp_file(char *buffer, size_t length) {
  int fd = mkstemp(temp_filename);

  unlink(temp_filename);

  /* Write the number of bytes to the file first. */
  write(fd, &length, sizeof(length));

  /* Now write the data itself. */
  write(fd, buffer, length);

  return fd;
}

char *read_temp_file(HANDLE temp_file, size_t *length) {
  char *buffer;
  int fd = temp_file;

  /* Rewind to the beginning of the file. */
  lseek(fd, 0, SEEK_SET);

  /* Read the size of the data in the temporary file. */
  read(fd, length, sizeof(*length));

  /* Allocate a buffer and read the data. */
  buffer = (char *)malloc(*length);
  read(fd, buffer, *length);

  close(fd);
  return buffer;
}

int main(void) {
  char buffer[] = "salam yow";
  int fd;
  fd = write_temp_file(buffer, sizeof(buffer));
  sleep(10);

  /*    read_temp_file(fd, (size_t*)sizeof(buffer)); */

  return 0;
}
