/*
$Id: sign_int_shift.c 5 2007-03-31 15:04:06Z Makhtar $
Experiment with Signed, Unsigned integer shifting.
*/

#include <stdio.h>

#define WORD_SIZE ( sizeof ( INTEGER int ) * 8 )
#define NIBBLE_SIZE 4
#define NIBBLES_IN_WORD (( WORD_SIZE ) / NIBBLE_SIZE )
#define SIGN_BIT ( 1 << ( WORD_SIZE - 1 ))

char *title[] = { "\n       Signed             Unsigned",
                  "\n                 Signed                                 Unsigned"
                };

int
main (void)
{
    INTEGER int a;		/* look at the footnote */
    unsigned INTEGER int b, mask;
    int ab, i, j, bit_counter, line_counter;

    a = b = SIGN_BIT;
    printf ("%s\n\n", title[(WORD_SIZE == 16) ? 0 : 1]);

    for (line_counter = 0; line_counter < WORD_SIZE; line_counter++) {
        for (ab = 0; ab < 2; ab++) {
            mask = SIGN_BIT;
            for (i = 0; i < NIBBLES_IN_WORD; i++) {
                for (j = 0; j < NIBBLE_SIZE; j++) {
                    printf ("%c", (((ab) ? b : a) & mask) ? '1' : '0');
                    mask >>= 1;
                }
                printf (" ");
            }
            printf ("%s", (ab) ? "\n" : " ");
            if (ab) {
                b >>= 1;
            } else {
                a >>= 1;
#if defined(FIX_COMPILER_BUG)
# if (INTEGER == long)

                a |= SIGN_BIT;	/* This is a work-around for the 3b2 compiler bug. */
# endif
#endif

            }
        }
    }
    putchar ('\n');
    return 0;
}

/*
compile: gcc -olong.shifts -DFIX_COMPILER_BUG -DINTEGER=long  signIntShift.c
Then try :  gcc  -oshort.shifts -DINTEGER=short signIntShift.c
*/
