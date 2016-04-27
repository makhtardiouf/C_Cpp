/*
$Id: pthread_tsd.c 5 2007-03-31 15:04:06Z Makhtar $
Experiment with Thread Specific Data
*/

#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* Key used to associate a log file pointer with each thread */
static pthread_key_t thread_log_key;

/* Write log for the current thread.
The openning of the log file will be done by the parent. */
void write_log(const char *msg) {
  FILE *thread_log = (FILE *)pthread_getspecific(thread_log_key);
  fprintf(thread_log, "%s\n", msg);
}

/* `Cleanup function'; Close the log file. */
void close_log_file(void *thread_log) { fclose((FILE *)thread_log); }

/* The "heart" of each thread */
void *thread_fun(void *args) {
  char log_file[20];
  FILE *thread_log;
  char msg[100];

  /*
  Generate a filename for this thread's log file,
  using the thread's ID.
  */
  sprintf(log_file, "thread_%d.log", (int)pthread_self());

  /* Open the log file for writting */
  thread_log = fopen(log_file, "w");

  if (thread_log != NULL) {
    /* Store the file pointer in TSD under thread_log_key */
    pthread_setspecific(thread_log_key, thread_log);

    sprintf(msg, "\nLog file for the running thread number %d\n",
            (int)pthread_self());

    write_log(msg);

    printf("\nLog written. Now let me continue my work...\n");
  } else
    perror("\nOpen of log file for current thread");

  return NULL;
}

enum { NUMBER_OF_BABIES = 3 };

int main(void) {
  int i;
  pthread_t baby_thread[NUMBER_OF_BABIES];

  /* Create a key to associate thread log file pointers in TSD.
  Use the function close_log_file to clean up. */
  pthread_key_create(&thread_log_key, close_log_file);

  /* Create threads to do the work */
  for (i = 0; i < NUMBER_OF_BABIES; ++i)
    pthread_create(&(baby_thread[i]), NULL, thread_fun, NULL);

  /* Wait for all threads to finish */
  for (i = 0; i < NUMBER_OF_BABIES; ++i)
    pthread_join(baby_thread[i], NULL);

  return EXIT_SUCCESS;
}
