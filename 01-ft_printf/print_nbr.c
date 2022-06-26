/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:50:26 by yubchoi           #+#    #+#             */
/*   Updated: 2022/01/01 15:50:27 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(char type, unsigned long nbr)
{
	int		len;
	int		tmp;
	char	*base;

	base = check_base(type);
	len = 0;
	if ((type == 'd' || type == 'i') && (int)nbr < 0)
	{
		len = write(1, "-", 1);
		nbr *= -1;
	}
	else if (type == 'p')
	{
		len = write(1, "0x", 2);
	}
	if (len == ERR)
		return (ERR);
	tmp = ft_put_nbr(type, nbr, base);
	if (tmp == ERR)
		return (ERR);
	len += tmp;
	return (len);
}

char	*check_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

int	ft_put_nbr(char type, unsigned long nbr, char *base)
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
