#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strerr(char *msg)
{
	int len = 0;

	while (msg && msg[len])
		++len;
	write(1, msg, len);
	return 1;
}

int clear_all(FILE *file, char *drawing, char *msg)
{
	fclose(file);
	free(drawing);
	if (msg)
		ft_strerr(msg);
	return 1;
}
