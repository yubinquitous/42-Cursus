#include "ft_printf.h"

int	print_char(int c)
{
	if (ft_putchar((char)c) == ERR)
		return (ERR);
	return (1);
}