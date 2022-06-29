#include "../include/pipex.h"
#include "../lib/libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char **find_path(char **envp)
{
    int i;
    char **path;

    i = -1;
    while (envp[++i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            path = ft_split(ft_strdup(envp[i] + 5), ':');
            return (path);
        }
    }
    error_exit("PATH not found", 127);
    return (NULL);
}

void str_test(char *msg, char **str)
{
    printf("=====%s======\n", msg);
    while (*str)
    {
        printf("%s\n", *str);
        ++str;
    }
}

char *find_cmd(char *cmd, char **path)
{
    char **tmp_path;
    char *path_cmd;

    tmp_path = path;
    while (*tmp_path)
    {
        path_cmd = ft_strjoin(*tmp_path, cmd);
        if (access(path_cmd, X_OK) == 0)
        {
            // printf("path_cmd : %s\n", path_cmd); // test
            return (path_cmd);
        }
        ++tmp_path;
    }
    error_exit("Command not found", 127);
    return (NULL);
}

void free_all(char **str)
{
    int i;

    i = -1;
    while (str[++i])
        free(str[i]);
    free(str);
}

void init(t_arg *arg, int argc, char **argv, char **envp)
{
    t_arg arg1;
    t_arg arg2;

    arg1.file = argv[1];
    arg2.file = argv[4];
    arg1.path = find_path(envp);
    arg2.path = arg1.path;
    arg1.option = ft_split(ft_strjoin("/", argv[2]), ' ');
    arg2.option = ft_split(ft_strjoin("/", argv[3]), ' ');
    arg1.cmd = find_cmd(arg1.option[0], arg1.path);
    arg2.cmd = find_cmd(arg2.option[0], arg2.path);
    // str_test("arg1.option", arg1.option);
    // str_test("arg2.option", arg2.option);
    arg = &arg1;
    arg->next = &arg2;
}

void fork_and_exec(t_arg arg)
{
    int i;
    pid_t pid;
    t_arg *tmp_arg;
    int pipe_fd[2];

    i = 1;
    pipe(pipe_fd);
    tmp_arg = &arg;
    while (tmp_arg)
    {
        pid = fork();
        if (pid == -1)
            error_exit("fork error", 1);
        else if (pid == 0)
            do_child(*tmp_arg, pipe_fd, i);
        // else
        //     do_parent(arg);
        tmp_arg = tmp_arg->next;
        ++i;
    }
}

int main(int argc, char **argv, char **envp)
{
    t_arg arg;

    // if (argc != 5)
    //     return (0);
    init(&arg, argc, argv, envp);
    // fork_and_exec(arg);

    return (0);
}