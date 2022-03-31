#include "../includes/so_long.h"

void	ft_exit(char *msg)
{
	printf("%s\n", msg);
	system("leaks so_long > leaks_result; cat leaks_result && rm -rf leaks_result");
	exit(1);
}
