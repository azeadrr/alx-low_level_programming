#include "main.h"

/**
 * append_text_to_file - adds text in the end of a file
 * @filename: point to the name of the file
 * @text_content: the string that should be added at the end of the file
 * Return: The function returns 1 upon successful execution and
 * -1 upon failure,
 * the function does not create the file if it does not exist,
 * if the filename parameter is NULL, the function returns -1,
 * if the text_content parameter is NULL, no content is added to the file,
 * the function returns 1 if the file exists, and -1 if the file does not exist
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int ot, wr, re = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (re = 0; text_content[re];)
			re++;
	}

	ot = open(filename, O_WRONLY | O_APPEND);
	wr = write(ot, text_content, re);

	if (ot == -1 || wr == -1)
		return (-1);

	close(ot);

	return (1);
}
