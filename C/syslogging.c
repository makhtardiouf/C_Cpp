/*
$Id: syslogging.c 18 2008-07-06 09:18:48Z Makhtar $

Test les utilitaires syslog
*/

#include "malib.h"

#define IDNAME "vocvoting"

int main(void) {
  int i = 0;
  char *buff;
  char *dateStr;
  time_t currentTm;
  struct tm *dateTm = (struct tm *)malloc(sizeof(struct tm *));
  int procId = (int)getpid();
  int sysUserId = (int)getuid();

  clearconsole();

  currentTm = time(NULL);
  dateTm = localtime(&currentTm);

  if (dateTm != NULL) {
    asprintf(&dateStr, "%02d.%02d.%04d", dateTm->tm_mday, dateTm->tm_mon + 1,
             dateTm->tm_year + 1900);
    printf("Date %s\n", dateStr);
  } else {
    printf("Date string is NULL\n");
    strcpy(dateStr, "unknown");
  }

  openlog(IDNAME, LOG_PERROR | LOG_CONS | LOG_PID, LOG_DAEMON);

  syslog(LOG_INFO, "***** Demarrage de %s... *****", IDNAME);

  for (i; i < 5; i++)
    syslog(LOG_INFO, "Welcome to the syslog world.\tYour are at index No. %d",
           i);

  syslog(LOG_DEBUG, "***** Arret de %s... *****", IDNAME);

  /* sprintf(buff, "fgrep %s /var/log/messages > /var/log/%s-%s.log", IDNAME,
   * IDNAME, dateStr); */

  if (sysUserId != 0)
    syslog(LOG_ERR,
           "You need to be root user to write to /var/log - Error: %m");
  else {
    asprintf(&buff, "fgrep %s /var/log/messages > /var/log/%s.log", IDNAME,
             IDNAME);
    system(buff);
  }

  closelog();
  return EXIT_SUCCESS;
}
