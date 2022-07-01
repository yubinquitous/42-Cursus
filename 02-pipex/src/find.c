/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:47:41 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/01 13:54:31 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../include/pipex.h"
#include <unistd.h>
#include <stdlib.h>

char	**find_path(char **envp)
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

char	*find_cmd_path(char *cmd, char **paths)
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
