/*
$Id: pthread_primes.c 5 2007-03-31 15:04:06Z Makhtar $
Compute successive prime numbers using threads
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

/*
Compute successive prime numbers.
Return the Nth prime number, where N is the value
pointed to by *arg
 */
void* compute_prime(void* arg)
{
    int candidate = 2;
    int n = *((int*) arg);

    for (;;)			/* forever */
    {
        int factor;
        int is_prime = 1;

        /* Test primality by successive division */
        for (factor = 2; factor < candidate; ++factor)
        {
            if ((candidate % factor) == 0) {
                is_prime = 0;
                break;
            }

            /* Got the target? */
            else if (is_prime) {
                if (--n == 0)
                    return (void*)candidate;
            }
            ++candidate;
        }
    }
    return NULL;
}


int main(int argc, char* argv[])
{
    pthread_t baby_thread;
    int which_prime;
    int prime;

    /* convert acceptable input to long in decimal base mode */
    if ( (argc <= 1) || (which_prime = strtoul(argv[1], NULL, 0)) <= 0 ) {
        fprintf(stderr, "\nUsage: %s POSITIVE_NUMBER\n", argv[0]);
        /*       return EXIT_FAILURE; */
        exit(EXIT_FAILURE);
    }

    printf("\nYou entered %d as arg\n", which_prime);


    /* Start the computing thread, up to `which_prime'th
       prime number */
    pthread_create(&baby_thread, NULL, &compute_prime,
                   &which_prime);

    /* Wait for the prime number thread to complete, and
    get the result */
    pthread_join(baby_thread, (void*) &prime);

    /* Print the largest prime computed */
    printf("\nThe %dth prime number is %d.\n", which_prime, prime);

    return EXIT_SUCCESS;
}
