/*
$Id: fork_exec.c 9 2007-07-11 08:22:53Z Makhtar $

*/

#include <errno.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "malib.h"

static pid_t spawn(char *program, char **arg_list);

int main(int argc, char *argv[]) {
  /*
  arg list to pass to the child program (ls)
  should contain the name of the program
  */
  char *arg_list[] = {"ls", "-l", "../", NULL};

  spawn("ls", arg_list);
  printf("Done with main program\n");

  return EXIT_SUCCESS;
}

pid_t spawn(char *program, char **arg_list) {
  pid_t child_pid;
  /* duplicate this process */
  child_pid = fork();
  if (child_pid != 0)
    /* this is the parent process */
    return child_pid;
  else {
    /* Now execute PROGRAM, using $PATH */
    execvp(program, arg_list);
    /* The execvp function returns only if an error occurs */
    error(0, errno, "In function `execvp', program %s", program);
    abort();
  }
}
