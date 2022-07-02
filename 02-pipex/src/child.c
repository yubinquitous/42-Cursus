/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:39:07 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/02 18:09:54 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <fcntl.h>
#include <stdlib.h>

void	do_child1(t_arg arg, int *pipe_fd)
{
	int	file_fd;

	ft_close(pipe_fd[0]);
	file_fd = ft_open(arg.file, O_RDONLY, -1);
	ft_dup2(file_fd, 0);
	ft_dup2(pipe_fd[1], 1);
	ft_execve(arg.exec_file, arg.exec_argv, NULL);
	ft_close(pipe_fd[1]);
	ft_close(file_fd);
}

void	do_child2(t_arg arg, int *pipe_fd)
{
	int	file_fd;

	ft_close(pipe_fd[1]);
	file_fd = ft_open(arg.file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_dup2(pipe_fd[0], 0);
	ft_dup2(file_fd, 1);
	ft_execve(arg.exec_file, arg.exec_argv, NULL);
	ft_close(pipe_fd[0]);
	ft_close(file_fd);
}

void	do_child(t_arg arg, int *pipe_fd, int i)
{
	if (i == 1)
		do_child1(arg, pipe_fd);
	else
		do_child2(arg, pipe_fd);
	exit(0);
}
