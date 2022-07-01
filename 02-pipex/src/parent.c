/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:41:10 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/01 13:51:31 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <sys/wait.h>

void	do_parent(int *pipe_fd, int i)
{
	if (i > 1)
	{
		ft_close(pipe_fd[1]);
		ft_close(pipe_fd[0]);
	}
}
