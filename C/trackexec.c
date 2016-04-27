/*
$Id: fork_exec_wait.c 9 2007-07-11 08:22:53Z Makhtar $
Exec and wait
*/

#include <errno.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static pid_t spawn(char *program, char **arg_list);

int main(int argc, char *argv[]) {
  int child_status = 0;
  char *msg[256];
  char *arg_list[256];
  int i = 1;
  int j = 0;

  while (i <= argc) {
    arg_list[j] = argv[i];
    i++;
    j++;
  }
  arg_list[++j] = NULL;
  spawn(argv[1], arg_list);

  /* Wait for the child process to complete */
  wait(&child_status);
  if (WIFEXITED(child_status)) {
    /*printf( "The child process exited normally, with exit code %d\n",
      WEXITSTATUS(child_status) );*/
    sprintf(msg, "xmessage The program %s exited with code %d &", argv[1],
            WEXITSTATUS(child_status));
    system(msg);

  } else
    fprintf(stderr, "The child process exited abnormally, with exit code %d\n",
            WEXITSTATUS(child_status));

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
    /* Now execute PROGRAM, searching for it in the path */
    execvp(program, arg_list);
    /* The execvp function returns only if an error occurs */
    error(0, errno, "In function `execvp', program %s", program);
    abort();
  }
}
