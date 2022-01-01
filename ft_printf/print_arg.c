/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:28:24 by yubchoi           #+#    #+#             */
/*   Updated: 2022/01/01 14:16:22 by yubinquit        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int	check_nbr_len(char type, unsigned long nbr)
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
*/

char	*check_base(char type)
{
	if (type == 'd' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

int	ft_put_nbr(char type, unsigned long nbr, char *base)
{
	int	tmp;
	int	num;
	int	ret;

	if (type == 'd' || type == 'i' || type == 'u')
	{
		num = 10;
		tmp = ft_put_nbr(type, nbr / num, base);
	}
	else
	{
		num = 16;
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

int	print_nbr(char type, unsigned long nbr)
{
	int		len;
	int		tmp;
	char	*base;

	base = check_base(type);
	//len = check_nbr_len(type, nbr);
	len = 0;
	if ((type == 'd' || type == 'i') && (int)nbr < 0)
	{
		tmp = write(1, "-", 1);
		if (tmp == ERR)
			return (ERR);
		nbr *= -1;
		len = tmp;
	}
	tmp = ft_put_nbr(type, nbr, base);
	if (tmp == ERR)
		return (ERR);
	else
		len += tmp;
	return (len);
}

int	print_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!str)
		len = write(1, "(null)", 6);
	else
	{
		if (ft_putstr_fd(str, 1) == ERR)
			return (ERR);
	}
	return (len);
}

int	print_char(char	c)
{
	if (ft_putchar_fd(c, 1) == ERR)
		return (ERR);
	return (1);
}
