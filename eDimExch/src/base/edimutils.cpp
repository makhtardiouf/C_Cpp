/*****************************************************************
 * $Id: edimutils.cpp 7 2007-05-22 15:03:42Z makhtar $
 * Copyright (C) 2006-2007 Makhtar Diouf
 * elmakdi@users.sourceforge.net
 *
 * -You can redistribute and/or modify this program
 *  under the terms of the GNU General Public License version 2.
 *  See the file COPYING for further information.
 *
 * -Vous pouvez redistribuer et/ou modifier ce programme
 *  sous les termes de la license GNU General Public version 2.
 *  Voir le fichier COPYING pour plus d'information.
 ****************************************************************/

/** Implementation of C specific utility functions */

/* Get access to popen, pclose, usleep */
#define _BSD_SOURCE
#include "edimutils.h"
#include <unistd.h>
#include <csignal>
#include <string>

int
clearconsole(void)
{
    FILE* process;
#ifdef __unix__
    process = popen("clear", "w");
#elif defined __WIN32__
    process = popen("cls", "w");
#endif

    if (process != NULL) {
        pclose(process);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

void
handle_signal(int signum)
{
    if (signum == SIGSEGV)
        perror("\nSignal SIGSEGV catched");
    else if (signum == SIGTERM)
        perror("\nSignal SIGTERM catched");

    signal(signum, SIG_DFL);
    raise(signum);
}

void
pausethis(int microsec)
{
    usleep(microsec * 100000);
}

void
printBinary(const unsigned char val)
{
    int i;
    for ( i=7; i>=0; i--)
        if ( val & (1 << i) )
            putchar('1') ;
        else
            putchar('0') ;
}

char*
reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1;  i < j;  i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

int
show_menu(char* menu[])
{
    int choice = 0;
    int i = 0;
    int chances = 2;

    while (chances--) {
        pausethis(1);

        for ( ; menu[i] != NULL; ++i ) {
            printf("%3d:   %s \n", i, menu[i]);
            pausethis(1);
        }

        printf("\nEnter your choice: ");
        scanf("%d", &choice );
        getchar();   /* absorb the garbage */

        /*  if ( isdigit(choice) && (choice >= 0) && (choice <= i-1) ) */
        if ( (choice >= 0) && (choice <= i-1) )
            break;
        else
            fprintf(stderr, "\nInvalid input" );
    }
    fprintf(stderr, "\n");
    return choice;
}

void
slowcout(const char* string)
{
    while (*string != '\0') {
        /*  putchar(*name);
          _flushlbf();*/
        fprintf(stderr, "%c", *string);
        ++string;
        pausethis(1);
    }
}

void
w32_wait(void)
{
    printf("\nPress a key to exit...") ;
    getchar();
}

int spawn(const char* cmd[] )
{
    std::string command(cmd[0]);
    for (int i = 1; cmd[i] != NULL; ++i) {
        command.append(" -");
        command.append(cmd[i]);
    }

    FILE* process;
    if ( (process = popen(command.c_str(), "w")) != NULL) {
        pclose(process);
        return EXIT_SUCCESS;
    }
    perror(cmd[0]);
    return EXIT_FAILURE;
}
