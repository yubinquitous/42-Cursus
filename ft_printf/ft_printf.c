/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:06:09 by yubchoi           #+#    #+#             */
/*   Updated: 2021/12/31 15:42:51 by yubinquit        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *arg, ...)
{
	int		nprintf;
	va_list	ap;
	char	*str;

	va_start(ap, arg);
	str = arg;
	if (ft_strchr(str, '%'))
		nprintf = (int)write(1, str, ft_strlen(str));
	else
		nprintf = parse_arg(ap, str);
	va_end(ap);
	return (nprintf);
}
