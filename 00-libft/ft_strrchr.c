/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:47:10 by yubchoi           #+#    #+#             */
/*   Updated: 2021/12/01 11:52:02 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*end;
	char		*prev;

	prev = 0;
	end = (char *)s;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (1)
	{
		end = ft_strchr(end, c);
		if (!end)
			return (prev);
		prev = end;
		++end;
	}
	return (NULL);
}
