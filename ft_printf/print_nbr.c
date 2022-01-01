#include "ft_printf.h"

int	print_nbr(char type, unsigned long nbr)
{
	int		len;
	int		tmp;
	char* base;

	base = check_base(type);
	len = 0;
	tmp = 0;
	if ((type == 'd' || type == 'i') && (int)nbr < 0)
	{
		tmp = write(1, "-", 1);
		nbr *= -1;
		len = tmp;
	}
	else if (type == 'p')
	{
		tmp = write(1, "0x", 2);
		len = tmp;
	}
	if (tmp == ERR)
		return (ERR);
	tmp = ft_put_nbr(type, nbr, base);
	if (tmp == ERR)
		return (ERR);
	else
		len += tmp;
	return (len);
}

char* check_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

int	ft_put_nbr(char type, unsigned long nbr, char* base)
{
	int				tmp;
	int				ret;
	unsigned long	num;

	tmp = 0;
	if (type == 'd' || type == 'i' || type == 'u')
	{
		num = 10;
		if (nbr >= num)
			tmp = ft_put_nbr(type, nbr / num, base);
	}
	else
	{
		num = 16;
		if (nbr >= num)
			tmp = ft_put_nbr(type, nbr / num, base);
	}
	if (tmp == ERR)
		return (ERR);
	ret = tmp;
	tmp = write(1, &base[nbr % num], 1);
	if (tmp == ERR)
		return (ERR);
	ret += tmp;
	return (ret);
}