#include "ft_printf.h"

int	nbr_len(char type, int nbr)
{
	int	len;
	int	base;

	len = 0;
	if (type == 'd' || type == 'i' || type == 'u')
		base = 10;
	else
		base = 16;
	if (nbr < 0)
	{
		++len;
		nbr *= -1;
	}
	while (nbr)
	{
		++len;
		nbr /= base;
	}
	return (len);
}

int	print_nbr(char type, int nbr)
{
	int	len;

	len = nbr_len(type, nbr);
	// d, i, u (x, X, p)까지 합칠 방법은 없는지 
	return (len);
}

int	print_hex(char type, unsigned long long nbr)
{
	int len;

	len = nbr_len(type, (int)nbr);
	return (len);
}

int	print_unsigned_nbr(char type, unsigned int nbr)
{
	int len;

	len = nbr_len(type, (int)nbr);
	return (len);
}

int	print_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

int	print_char(char	c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
