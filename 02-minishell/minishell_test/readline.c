#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line;
	while (1)
	{
		line = readline("read_line test > ");
		if (line)
			printf("line : %s\n", line);
		else
			break;
		free(line);
	}
	printf("done\n");
	return (0);
}