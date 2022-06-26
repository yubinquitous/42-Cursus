/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:02:43 by yubchoi           #+#    #+#             */
/*   Updated: 2021/12/01 17:46:19 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_len(size_t len, char const *s)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len < len)
		return (s_len);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*ret;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len = check_len(len, s);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
	{
		if (!(s[i]))
			break ;
		ret[j++] = s[i++];
	}
	ret[j] = '\0';
	return (ret);
}
