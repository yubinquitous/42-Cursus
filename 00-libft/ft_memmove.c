/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:15:32 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/29 18:22:00 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_c;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dst_c = (char *)dst;
	if (dst > src)
	{
		while (len--)
			*(dst_c + len) = *(char *)(src + len);
	}
	else
	{
		while (len--)
		{
			*dst_c++ = *(char *)src++;
		}
	}
	return (dst);
}
