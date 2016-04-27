/*
$Id$

*/

#include <sys/reboot.h>
#include <unistd.h>

int main(void) {
  reboot(LINUX_REBOOT_CMD_RESTART(RB_AUTOBOOT, 0x1234567));
  return 0;
}
