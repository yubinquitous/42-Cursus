/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:48:02 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/29 18:09:31 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ret;

	ret = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ret[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
