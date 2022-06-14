/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:39:55 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 21:16:10 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static char	**ft_malloc_ret(char *s, char c)
{
	size_t	cnt;
	char	**ret;

	cnt = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*ft_malloc_ret_n(char *str, char *start, char *end)
{
	int	i;

	str = (char *)malloc(end - start + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < end - start)
		str[i] = start[i];
	str[i] = 0;
	return (str);
}

void	*free_all(char **str, int l)
{
	int	i;

	i = 0;
	while (str[i] && i < l)
	{
		free(str[i]);
		++i;
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
			if (!ret[i++])
				return (free_all(ret, i));
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}
