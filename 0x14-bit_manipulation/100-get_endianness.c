#include "main.h"

/**
 * get_endianness - Checks if the machine is little or big endian.
 *
 * Return: 0 for big endian, 1 for little endian.
 */
int get_endianness(void)
{
    unsigned int i = 1;
    char *c = (char *) &i;

    /* If the least significant byte is stored first, the machine is little endian */
    return (*c == 1);
}
