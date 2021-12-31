#include "ft_printf.h"

int	parse_arg(va_list ap, char *arg)
{
	int		nprintf;

	nprintf = 0;
	while (*arg)
	{
		if (*arg != '%')
		{
			write(1, arg, 1);
			++nprintf;
		}
		else
		{
			++arg;
			if (check_format(ap, *arg, &nprintf) == ERR)
				return (ERR);
		}
		++arg;
	}
	return (nprintf);
}			
