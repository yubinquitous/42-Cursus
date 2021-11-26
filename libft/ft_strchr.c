/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:39:54 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/26 14:02:34 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *)s;
	while (i < ft_strlen(s))
	{
		if (dst[i] == c)
			return (&(dst[i]));
		i++;
	}
	return (NULL);
}
