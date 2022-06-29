/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:11:39 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/29 15:55:28 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../include/pipex.h"
#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2)
{
	char *ret;
	int len_s1;
	int len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	ret = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ret)
		error_exit("malloc error", 2);
	ft_strlcpy(ret, (char *)s1, len_s1 + 1);
	ft_strlcat(ret, (char *)s2, len_s1 + len_s2 + 1);
	return (ret);
}
