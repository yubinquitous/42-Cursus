/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:27:32 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/01 17:33:01 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../include/pipex.h"
#include <unistd.h>
#include <stdlib.h>

static char	**find_path(char **envp)
{
	int		i;
	char	**path;

	i = -1;
	path = NULL;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split((envp[i] + 5), ':');
			return (path);
		}
	}
	free_all(path);
	error_exit("PATH not found", 127);
	return (NULL);
}

static char	*find_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;
	char	*tmp_cmd;

	i = -1;
	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (paths && paths[++i])
	{
		tmp_cmd = ft_strjoin("/", cmd);
		cmd_path = ft_strjoin(paths[i], tmp_cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free(tmp_cmd);
			return (cmd_path);
		}
		free(tmp_cmd);
		free(cmd_path);
	}
	return (NULL);
}

t_arg	init(char *file, char *cmd, char **envp)
{
	t_arg	arg;
	char	**paths;

	paths = find_path(envp);
	arg.file = file;
	arg.exec_argv = ft_split(cmd, ' ');
	arg.exec_file = find_cmd_path(arg.exec_argv[0], paths);
	free_all(paths);
	return (arg);
}
