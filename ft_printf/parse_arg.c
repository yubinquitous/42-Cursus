#include "ft_printf.h"

int	parse_arg(va_list ap, const char *arg)
{
	int	nprintf;
	int	type;

	nprintf = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			++nprintf;
		}
		else
		{
			++str;
			if (check_format(ap, *str, &nprintf) == ERR)
				return (ERR);
		}
		++str;
	}
	return (nprintf);
}			
