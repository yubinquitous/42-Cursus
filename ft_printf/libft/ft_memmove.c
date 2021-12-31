/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:15:32 by yubchoi           #+#    #+#             */
/*   Updated: 2021/12/31 18:17:23 by yubinquit        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_c;

	if (!dst && !src)
		return (NULL);
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
