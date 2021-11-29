/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:02:43 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/29 16:47:49 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*ret;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
	{
		if (!(s[i]))
			return (ret);
		ret[j] = s[i];
		i++;
		j++;
		ret[j] = '\0';
	}
	return (ret);
}
