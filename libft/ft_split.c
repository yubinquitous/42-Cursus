/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:07:09 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/29 16:48:48 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_ret(char *s, char c)
{
	size_t	cnt;
	char	**ret;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			s++;
		}
		else
			s++;
	}
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	return (ret);
}

static char	*ft_malloc_ret_n(char *str, char *start, char *end)
{
	int	i;

	str = (char *)malloc(end - start + 1);
	i = -1;
	while (++i < end - start)
		str[i] = start[i];
	str[i] = 0;
	return (str);
}

static void	*free_all(char **str, size_t l)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL && i < l)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*start;
	size_t	i;

	ret = ft_malloc_ret((char *)s, c);
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			ret[i] = ft_malloc_ret_n(ret[i], start, (char *)s);
			if (!ret[i])
				return (free_all(ret, i));
			i++;
		}
		s++;
	}
	ret[i] = 0;
	return (ret);
}
