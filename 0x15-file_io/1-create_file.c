#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int dr, wr, re = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (re = 0; text_content[re];)
			re++;
	}

	dr = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(dr, text_content, re);

	if (dr == -1 || wr == -1)
		return (-1);

	close(dr);

	return (1);
}

