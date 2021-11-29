/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:13:00 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/29 16:27:31 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_len(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*ft_ntoret(char *ret, long long n, int len)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		n *= -1;
		ret[0] = '-';
		cnt++;
	}
	while (cnt < len)
	{
		ret[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;

	len = ft_cnt_len(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret = ft_ntoret(ret, (long long)n, len);
	ret[len] = 0;
	return (ret);
}
