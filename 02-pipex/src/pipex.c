/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:41:15 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/01 17:33:40 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

void	fork_and_exec(t_arg arg)
{
	pid_t	pid;
	t_arg	tmp_arg;
	int		pipe_fd[2];
	int		i;

	i = 1;
	pipe(pipe_fd);
	tmp_arg = arg;
	while (1)
	{
		pid = fork();
		if (pid == -1)
			error_exit("fork error", 1);
		else if (pid == 0)
			do_child(tmp_arg, pipe_fd, i);
		else
			do_parent(pipe_fd, i);
		if (!tmp_arg.next)
			break ;
		tmp_arg = *(tmp_arg.next);
		++i;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	t_arg	arg2;

	if (argc != 5)
		return (0);
	arg = init(argv[1], argv[2], envp);
	arg2 = init(argv[4], argv[3], envp);
	arg2.next = NULL;
	arg.next = &arg2;
	fork_and_exec(arg);
	while (wait((int *)0) != -1)
		;
	return (0);
}
