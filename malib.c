/* $Id: malib.c 9 2007-07-11 08:22:53Z Makhtar $
Implementation of C utility functions */

#include "malib.h"
#include <unistd.h>

void terminate(const char* s) {
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

void rotate_dash(void) {
    int i = 0;
    const char* dash[] = {"|", "/", "*", "\\", " "};

    /*     while (1) */
    for (; i <= 4; i++) {
        fprintf(stderr, "%s", dash[i]);
        pausethis(1);
        fprintf(stderr, "\b");
    }
}

int clearconsole(void) {
    /* #define _BSD_SOURCE */
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
    /* #undef _BSD_SOURCE */

    return EXIT_FAILURE;
}

void handle_signal(int signum) {
    if (signum == SIGSEGV)
        perror("\nSignal SIGSEGV catched");
    else if (signum == SIGTERM)
        perror("\nSignal SIGTERM catched");

    signal(signum, SIG_DFL);
    raise(signum);
}

void pausethis(int sec) {
    usleep(sec * 100000);
}

void printBinary(const unsigned char val) {
    int i;
    for (i = 7; i >= 0; i--)
        if (val & (1 << i))
            putchar('1');
        else
            putchar('0');
}

char* reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

int show_menu(char* menu[]) {
    int choice = 0;
    int i = 0;
    int chances = 2;

    while (chances--) {
        pausethis(1);

        for (; menu[i] != NULL; ++i) {
            printf("%3d:   %s \n", i, menu[i]);
            pausethis(1);
        }

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); /* get the garbage */

        /*  if ( isdigit(choice) && (choice >= 0) && (choice <= i-1) ) */
        if ((choice >= 0) && (choice <= i - 1))
            break;
        else
            fprintf(stderr, "\nInvalid input");
    }
    fprintf(stderr, "\n");
    return choice;
}

void slowprint(const char* string) {
    while (*string != '\0') {
        fprintf(stderr, "%c", *string);
        ++string;
        pausethis(1);
    }
}

void w32_wait(void) {
    printf("\nPress a key to exit...");
    getchar();
}

char* remove_duplicates(char str[]) {
    int isDup = 0;

    for (u_int8_t i = 0; i < strlen(str) - 1; i++) {

        for (u_int8_t j = strlen(str) - 1; j >= 0; j--) {
            if (str[i] == str[j])
                isDup++;

            if (isDup > 1) {
                printf("Caught duplicate: %c\n", str[j]);
                //  p[i] = '0';
                isDup--;
            }
        }
    }
    // str[tail] = '\0';
    return str;
}
