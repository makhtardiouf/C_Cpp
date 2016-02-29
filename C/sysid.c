/*
$Id: sysid.c 5 2007-03-31 15:04:06Z Makhtar $
Find information about the host and print the environment variables
*/

#define _GNU_SOURCE
#include "malib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>


typedef char* String;

int main(void)
{
    struct utsname sysinfo;
    struct passwd* user = getpwnam(getlogin());
    int i;

    /* set a handler for the segmentation violation error */
    if (signal(SIGSEGV, handle_segv) == SIG_ERR)
        perror("\nCould not set a handler for SIGSEGV");

    printf("login name: %s\n"
           "home dir: %s\n",
           user->pw_name,
           user->pw_dir);

    if (uname(&sysinfo) == -1)
        perror("Getting system info");
    else {
        puts(sysinfo.sysname);
        puts(sysinfo.release);
        puts(sysinfo.version);
    }

    /* Print the environment variables of the host */
    puts("\n\tEnvironment variables: ");
    for (i = 0; environ[i] != NULL; i++) {
        printf("\n> %s\n", environ[i]);
        pausethis(1);
    }

    puts("\n");

    return EXIT_SUCCESS;
}
