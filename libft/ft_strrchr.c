/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:47:10 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/26 14:02:16 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*dst;

	i = ft_strlen(s) - 1;
	dst = (char *)s;
	while (i >= 0)
	{
		if (dst[i] == c)
			return (&(dst[i]));
		i--;
	}
	return (NULL);
}
