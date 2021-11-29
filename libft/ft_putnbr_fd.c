/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:40:26 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/29 16:49:40 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	while (n >= 10)
	{
		ft_putchar_fd((n % 10) + '0', fd);
		n /= 10;
	}
	ft_putchar_fd(n + '0', fd);
}
