#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, or 0 if an error occurs
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	/* Iterate through the binary string */
	for (i = 0; b[i]; i++)
	{
		/* Check if the character is a valid binary digit */
		if (b[i] < '0' || b[i] > '1')
			return (0);

		/* Convert binary to decimal */
		dec_val = 2 * dec_val + (b[i] - '0');
	}

	return (dec_val);
}
