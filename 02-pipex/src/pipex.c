/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:41:15 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/01 13:41:15 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void free_all(char **str)
{
    int i;

    i = -1;
    while (str && str[++i])
    {
        free(str[i]);
        str[i] = 0;
    }
    free(str);
    str = 0;
}

char **find_path(char **envp)
{
    int i;
    char **path;

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

void str_test(char *msg, char **str)
{
    int i = 0;

    printf("=====%s======\n", msg);
    while (str && str[i])
    {
        printf("%s\n", str[i]);
        ++i;
    }
}

char *find_cmd_path(char *cmd, char **paths)
{
    int i;
    char *cmd_path;
    char *tmp_cmd;

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

t_arg init(char *file, char *cmd, char **envp)
{
    t_arg arg;
    char **paths;

    paths = find_path(envp);
    arg.file = file;
    arg.exec_argv = ft_split(cmd, ' ');
    arg.exec_file = find_cmd_path(arg.exec_argv[0], paths);
    free_all(paths);
    return (arg);
}

void fork_and_exec(t_arg arg)
{
    int i;
    pid_t pid;
    t_arg tmp_arg;
    int pipe_fd[2];

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
        {
            do_parent(pipe_fd, i);
            if (!tmp_arg.next)
                break;
            tmp_arg = *(tmp_arg.next);
            ++i;
        }
    }
}

int main(int argc, char **argv, char **envp)
{
    t_arg arg;
    t_arg arg2;

    if (argc != 5)
        return (0);
    arg = init(argv[1], argv[2], envp);
    arg2 = init(argv[4], argv[3], envp);
    arg2.next = NULL;
    arg.next = &arg2;
    fork_and_exec(arg);
    while (wait((int *)0) != -1)
        ;
    // system("leaks pipex");
    return (0);
}