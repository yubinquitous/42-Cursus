#include "ft_printf.h"

int	nbr_len(char type, unsigned long long nbr)
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

int	print_nbr(char type, unsigned long long nbr)
{
	int	len;

	len = nbr_len(type, nbr);
	if (type == 'd' || type == 'i')
		//ft_putnbr_fd를 커스텀해야하나?
	return (len);
}

int	print_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	ft_putstr_fd(s, 1);
	return (len);
}

int	print_char(char	c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
