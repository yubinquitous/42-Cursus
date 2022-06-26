/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:49:49 by yubchoi           #+#    #+#             */
/*   Updated: 2022/01/01 15:49:50 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!str)
		len = (int)write(1, "(null)", 6);
	else
		len = ft_putstr(str);
	return (len);
}
