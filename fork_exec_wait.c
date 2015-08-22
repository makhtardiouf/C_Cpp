/*
$Id: fork_exec_wait.c 9 2007-07-11 08:22:53Z Makhtar $
Exec and wait
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <error.h>
#include <errno.h>
#include "malib.h"

static pid_t spawn(char* program, char** arg_list);

int main(int argc, char* argv[])
{
    int child_status = 0;
    char* arg_list[] = { "ls", "-l", "../", NULL};

    spawn("ls", arg_list);

    /* Wait for the child process to complete */
    wait(&child_status);
    if ( WIFEXITED(child_status) )
        printf( "The child process exited normally, with exit code %d\n",
                WEXITSTATUS(child_status) );
    else
        fprintf(stderr, "The child process exited abnormally, with exit code %d\n",
                WEXITSTATUS(child_status) );

    return EXIT_SUCCESS;
}


pid_t spawn(char* program, char** arg_list)
{
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
