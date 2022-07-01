/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:39:18 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/01 13:39:48 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

typedef struct s_arg
{
    char *file;
    char **exec_argv;
    char *exec_file;
    struct s_arg *next;
} t_arg;

void error_exit(char *msg, int status);
void ft_close(int fd);
void ft_dup2(int fd, int fd2);
int ft_open(char *file, int mode, int access);
void ft_execve(char *file, char **argv, char **envp);
void do_child(t_arg arg, int *pipe_fd, int i);
void do_parent(int *pipe_fd, int i);

#endif