/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:39:46 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 20:39:47 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

static int is_space(char c)
{
    if (c == '\t' || c == '\f' || c == '\n' || c == '\r' || c == '\v' || c == ' ')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int i;
    long sign;
    long result;

    i = 0;
    while (is_space(str[i]))
        ++i;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        ++i;
    }
    result = 0;
    if (!ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
        error_exit();
    while (ft_isdigit(str[i]))
        result = (result * 10) + (str[i++] - '0');
    if (result * sign < -2147483648 || result * sign > 2147483647)
        error_exit();
    return (result * sign);
}
