#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file print to STDOUT
 * @filename: text file being read
 * @letters: number of letters to be read
 * Retuen: actual number of bytes read and printed, 0 when function
 * failsor filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *ch;
	ssize_t df;
	ssize_t wr;
	ssize_t bf;

	df = open(filename, O_RDONLY);
	if (df == -1)
		return (0);
	ch = malloc(sizeof(char) * letters);
	bf = read(df, ch, letters);
	wr = write(STDOUT_FILENO, ch, bf);

	free(ch);
	close(df);
	return (wr);
}
