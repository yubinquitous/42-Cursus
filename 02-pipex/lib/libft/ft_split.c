/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:39:56 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/01 17:08:25 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
#include <stdlib.h>

static char	**ft_malloc_ret(char *s, char c)
{
	size_t	cnt;
	char	**ret;
	int		i;

	cnt = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				++i;
		}
		else
			++i;
	}
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!ret)
		error_exit("malloc error", 1);
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

static void	free_all_exit(char **str, int l)
{
	int	i;

	i = 0;
	while (str[i] && i < l)
	{
		free(str[i]);
		++i;
	}
	free(str);
	error_exit("malloc error", 2);
}

char	**ft_split(char *s, char c)
{
	char	**ret;
	char	*start;
	size_t	i;
	size_t	j;

	ret = ft_malloc_ret((char *)s, c);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = &s[i];
			while (s[i] && s[i] != c)
				++i;
			ret[j] = ft_malloc_ret_n(ret[j], start, &s[i]);
			if (!ret[j++])
				free_all_exit(ret, j);
		}
		else
			++i;
	}
	ret[j] = 0;
	return (ret);
}
