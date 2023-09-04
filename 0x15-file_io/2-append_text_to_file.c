#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: Pointer to the name of the file.
 * @text_content: String to append to the file.
 *
 * Return: On success, returns 1. On failure, returns -1.
 *         Returns -1 if filename is NULL or file cannot be opened.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	/* Calculate the length of the text_content */
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	/* Open the file for appending */
	o = open(filename, O_WRONLY | O_APPEND);
	if (o == -1)
		return (-1);

	/* Append text_content to the file */
	w = write(o, text_content, len);
	if (w == -1)
	{
		close(o);
		return (-1);
	}

	/* Close the file */
	close(o);

	return (1);
}
