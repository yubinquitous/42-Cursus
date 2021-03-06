/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:48:48 by yubchoi           #+#    #+#             */
/*   Updated: 2022/01/01 15:48:55 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list ap, char type, int *nprintf)
{
	int	ret;

	if (type == 'd' || type == 'i')
		ret = print_nbr(type, va_arg(ap, int));
	else if (type == 'u' || type == 'x' || type == 'X')
		ret = print_nbr(type, va_arg(ap, unsigned int));
	else if (type == 'p')
		ret = print_nbr(type, va_arg(ap, unsigned long));
	else if (type == 's')
		ret = print_str(va_arg(ap, char *));
	else if (type == 'c')
		ret = print_char((char)va_arg(ap, int));
	else if (type == '%')
		ret = print_char('%');
	else
		return (ERR);
	*nprintf += ret;
	return (ret);
}
