#include "main.h"
#include <stdio.h>  /* Add this line to include the standard I/O library */

/**
 * print_binary - Prints the binary equivalent of a decimal number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
    int i, count = 0;
    unsigned long int current;

    for (i = 63; i >= 0; i--)
    {
        current = n >> i;

        if (current & 1)
        {
            putchar('1');  /* Use putchar from <stdio.h> */
            count++;
        }
        else if (count)
            putchar('0');  /* Use putchar from <stdio.h> */
    }
    if (!count)
        putchar('0');  /* Use putchar from <stdio.h> */
}
