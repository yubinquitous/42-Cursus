/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:23:29 by yubchoi           #+#    #+#             */
/*   Updated: 2021/12/01 19:08:28 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*ret;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = s1;
	end = s1 + ft_strlen(s1);
	while (*start && ft_strchr(set, *start))
		++start;
	while (start < end && ft_strchr(set, *(end - 1)))
		--end;
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, start, end - start + 1);
	return (ret);
}
