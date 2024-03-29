#include "main.h"

/**
 * create_file -to be create a file
 * @filename: point to the filename of the file to be created
 * @text_content: string pointer for the purpose of file writing
 * Return: if the function on success 1, -1 on failure
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
