#include <stdio.h>

int main(void)
{
	char *str = NULL;
	int ret = printf("%s", str);
	printf("%d\n", ret);
	return (0);
}
