/* nrandom.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number */
int get_random_number(void) {
    srand(time(NULL));  // Seed the random number generator with the current time
    return rand();  // Return a random number
}

