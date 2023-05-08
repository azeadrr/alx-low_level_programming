#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates a buffer with a size of 1024 bytes.
 * @file: characters are stored in the buffer for the file.
 * Return: pointer referencing the recently allocated buffer.
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - closes the file handles.
 * @fd: the file descriptor that requires closure.
 */

void close_file(int fd)
{
	int a;

	a = close(fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - transfers the contents of a file to a different file.
 * @argc: the count of arguments provided to the program.
 * @argv: a pointer array that holds references to the program's arguments.
 * Return : 0 indicates success.
 * note: if the argument count is incorrect, the program exits
 * with code 97
 * if the file specified by "file_from" does not exist or cannot be read,
 * the program exits with code 98
 * if the "file_to" cannot be created or written to, the program exits
 * with code 99
 * if either "file_to" or "file_from" cannot be closed,
 * the program exits with code 100
 */

int main(int argc, char *argv[])
{
	int from, to, re, wr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	re = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || re == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wr = write(to, buffer, re);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		re = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (re > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
