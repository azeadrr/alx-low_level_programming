#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Print the text file to STDOUT
 * @filename: text file in progress
 * @letters: number of letters toread
 * Return: actual number of letters read and printed, 0 if the function
 * fails or the filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *caf;
	ssize_t dr;
	ssize_t w;
	ssize_t x;

	dr = open(filename, O_RDONLY);
	if (dr == -1)
		return (0);

	caf = malloc(sizeof(char) * letters);
	x = read(dr, caf, letters);
	w = write(STDOUT_FILENO, caf, x);

	free(caf);
	close(dr);
	return (w);
}
