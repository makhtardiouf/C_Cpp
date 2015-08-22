/*
  $Id: rotate_dash.c 18 2008-07-06 09:18:48Z Makhtar $
  Display a rotating dash
*/

#include "emdutils.h"
/* #include <stdio.h> */

void test(void);		/* for testing stack size...etc */

int main(void)
{
    int i = 0;
    int bigarr[1000];
    bigarr[0] = 150;
    bigarr[1] = 1350;
    /*     char* dashes[] = {"|", "/", "*", "\\", NULL}; */
    fprintf(stderr, "Loading demo...  ");

    for (; i < 15; i++) {
        /* 	while((*dashes)++ != NULL) */
        /* 	{ */
        /* 	    fprintf(stderr, "%s", *dashes); */
        /* 	    pausethis(2); */
        /* 	    fprintf(stderr, "\b"); */
        /* 	} */
        /* 	*dashes = dashes[0]; */
        /* 	fprintf(stderr, "|"); pausethis(2); fprintf(stderr, "\b"); */
        /* 	fprintf(stderr, "/"); pausethis(2); fprintf(stderr, "\b"); */
        /* 	fprintf(stderr, "*"); pausethis(2); fprintf(stderr, "\b"); */
        /* 	fprintf(stderr, "\\"); pausethis(2); fprintf(stderr, "\b"); */
      /*      test();*/
        rotate_dash();
    }

    /*     fprintf(stderr, "\b"); */
    printf("\n");
    return 0;
}

void test(void){
  double bigarr[1000];
  double bigarr2[2000];
  /*  bigarr2[0] = 15.34;*/
  return;
}
