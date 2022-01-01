/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:33:30 by yubchoi           #+#    #+#             */
/*   Updated: 2022/01/01 14:17:51 by yubinquit        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (fd < 0 || !s)
		return (-1);
	len = ft_strlen(s);
	return (write(fd, s, len));
}
