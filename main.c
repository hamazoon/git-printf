#include "shell.h"
int main(int ac, char **argv)
{
	char *chaine = NULL;
	char **command = NULL;
	int status = 0;

	(void) ac;
	while (1)
	{
		chaine = read_line();
		if (chaine == NULL)
		{
			if (isatty(STDOUT_FILENO))
			write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = tokenizer(chaine);
		if (!command)
			continue;
		status = _execute(command, argv);
	}
}
