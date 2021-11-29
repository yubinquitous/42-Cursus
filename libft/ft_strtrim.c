/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:23:29 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/29 15:16:36 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && !(ft_strchr(set, s1[start])))
		start++;
	while (start < end && !(ft_strchr(set, s1[end])))
		end--;
	if (start == end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, &s1[start], (end - start) + 2);
	return (ret);
}
