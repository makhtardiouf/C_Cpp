/* $Id: aa_usleep_test.c 8 2007-04-30 22:25:20Z Makhtar $
Using the ascii art library
apt install libaa1-dev
*/
#include "malib.h"
#include <aalib.h>

aa_context *context;

int main(void) {
  int i;
  aa_parseoptions(NULL, NULL, NULL, NULL);
  context = aa_autoinit(&aa_defparams);
  aa_puts(context, 10, 100, AA_BOLD, "AA test");
  aa_flush(context);

  fprintf(stderr, "\nUsleep test:\n");
  for (i = 0; i < 200; i++) {
    if ((i % 20) == 0)
      fprintf(stderr, "\n");

    fprintf(stderr, ".");
    pausethis(3);
  }
  fprintf(stderr, "\n\n");

  aa_close(context);
  return EXIT_SUCCESS;
}
