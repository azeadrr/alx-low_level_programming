#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *create_buff(char *file);
void close_file(int fd);
/**
 * create_buff - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buff(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}
/**
 * close_file - Closes file descriptors.
 * @dr: The file descriptor to be closed.
 */
void close_file(int dr)
{
	int a;

	a = close(dr);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close dr %d\n", dr);
		exit(100);
	}
}
/**
 * main - Copies the contents of a file to another file.
 * @ac: The number of arguments supplied to the program.
 * @av: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int ac, char *av[])
{
	int wr, h, from, to;
	char *buff;
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buff = create_buff(av[2]);
	from = open(av[1], O_RDONLY);
	h= read(from, buff, 1024);
	to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || h == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", av[1]);
			free(buff);
			exit(98);
		}
		wr = write(to, buff, h);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", av[2]);
			free(buff);
			exit(99);
		}
		h = read(from, buff, 1024);
		to = open(av[2], O_WRONLY | O_APPEND);
	} 
	while (h > 0);
	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}
