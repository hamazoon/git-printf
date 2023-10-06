#include "shell.h"

char *read_line(void)
{
	char *chaine = NULL;
	size_t lenght = 0;
	ssize_t n;

	if (isatty(STDOUT_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&chaine, &lenght, stdin);
	if (n == -1)
	{
		free(chaine);
		return (NULL);
	}

	return (chaine);
}
