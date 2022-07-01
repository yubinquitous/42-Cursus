/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:41:17 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/01 13:41:18 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <unistd.h>
#include <fcntl.h>

void ft_execve(char *file, char **argv, char **envp)
{
    if (!file)
        error_exit("Command not found", 127);
    if (execve(file, argv, envp) == -1)
        error_exit("execve failed", 1);
}

void ft_close(int fd)
{
    if (close(fd) == -1)
        error_exit("close failed", 1);
}

void ft_dup2(int fd, int fd2)
{
    if (dup2(fd, fd2) == -1)
        error_exit("dup2 failed", 1);
}

int ft_open(char *file, int o_flag, int mode)
{
    int file_fd;

    if (mode == -1)
        file_fd = open(file, o_flag);
    else
        file_fd = open(file, o_flag, mode);
    if (file_fd == -1)
        error_exit("No such file or directory", 1);
    return (file_fd);
}