/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:28:24 by yubchoi           #+#    #+#             */
/*   Updated: 2022/01/01 01:13:14 by yubinquit        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		len;
	char	*base;

	if (type == 'd' || type == 'i' || type == 'u')
		base = "0123456789";
	else
		base = "0123456789abcdef";
	len = nbr_len(type, nbr);
	
	return (len);
}

int	print_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!str)
	{
		write(1, "(null)", 6);
		len = 6;
	}
	else
		ft_putstr_fd(str, 1);
	return (len);
}

int	print_char(char	c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
