/*
$Id: convert_deg_fah.c 6 2007-04-16 15:12:25Z Makhtar $
Print conversion table Celcius/Fahrenheit degrees
*/

#include "emdutils.h"

#define HEADER "Celcius\t  Fahrenheit"
#define FOOTER_LEN strlen(HEADER)

void display_footer(void);

int main(void)
{
    signed int cel_min = -50;
    signed int cel_max = 100;
    unsigned int step = 10;
    signed int i = cel_min;

    puts(HEADER);
    display_footer();

    for (; i <= cel_max; i += step) {
        printf("%5d\t|%8.2f ", i, (double)(((9 * i) / 5) + 32));
	fflush(stdout);
	rotate_dash();
	printf("\n");
    }

    display_footer();
    return EXIT_SUCCESS;
}

void display_footer(void)
{
    signed int i = 0;

    for (i = 0; i <= FOOTER_LEN; i++)
        printf("-");
    printf("\n");
}

