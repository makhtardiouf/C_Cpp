/* $Id: malib.c 9 2007-07-11 08:22:53Z Makhtar $
Implementation of C routines */

#include "malib.h"
#include <unistd.h>

double clockit() {
  static int isInit = 0;
  static clock_t t0 = 0;
  if (isInit == 0) {
    t0 = clock();
    isInit = 1;
    return 0.0;
  }

  clock_t t1 = clock();
  double diff = (t1 - t0) / (double)CLOCKS_PER_SEC;
  fprintf(stderr, "\nRuntime: %.4f s\n", diff);
  return diff;
}

void terminate(const char *s) {
  fprintf(stderr, "%s\n", s);
  exit(EXIT_FAILURE);
}

void rotate_dash(void) {
  int i = 0;
  const char *dash[] = {"|", "/", "*", "\\", " "};

  for (; i <= 4; i++) {
    fprintf(stderr, "%s", dash[i]);
    pausethis(1);
    fprintf(stderr, "\b");
  }
}

int clearconsole(void) {
  /* #define _BSD_SOURCE */
  FILE *process;
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

void pausethis(int sec) { usleep(sec * 100000); }

void printBinary(const unsigned char val) {
  int i;
  for (i = 7; i >= 0; i--)
    if (val & (1 << i))
      putchar('1');
    else
      putchar('0');
}

char *reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
  return s;
}

int show_menu(char *menu[]) {
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
    getchar();

    /*  if ( isdigit(choice) && (choice >= 0) && (choice <= i-1) ) */
    if ((choice >= 0) && (choice <= i - 1))
      break;
    else
      fprintf(stderr, "\nInvalid input");
  }
  fprintf(stderr, "\n");
  return choice;
}

void typewrite(const char *string) {
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

char *remove_duplicates(char str[]) {
  int isDup = 0;
  int len = strlen(str);
  for (u_int8_t i = 0; i < len - 1; i++) {

    for (u_int8_t j = len - 1; j >= 0; j--) {
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
