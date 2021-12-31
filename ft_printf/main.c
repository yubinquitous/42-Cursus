#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int ret;

	ret = printf(" %c \n", '0');
	printf("ret : %d\n", ret);
	ft_printf(" %c \n", '0');
	printf("ret : %d\n", ret);
}
