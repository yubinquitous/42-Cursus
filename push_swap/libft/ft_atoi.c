/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:39:46 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/15 15:55:24 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	check_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		++(*i);
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	while (is_space(str[i]))
		++i;
	sign = check_sign(str, &i);
	result = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error_exit();
		result = (result * 10) + (str[i++] - '0');
	}
	if (result * sign < -2147483648 || result * sign > 2147483647)
		error_exit();
	return (result * sign);
}
