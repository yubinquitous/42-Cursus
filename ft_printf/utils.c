/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:49:54 by yubchoi           #+#    #+#             */
/*   Updated: 2022/01/01 15:50:03 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		++s;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	return ((int)write(1, s, len));
}
