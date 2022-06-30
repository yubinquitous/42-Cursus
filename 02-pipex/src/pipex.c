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

char *find_cmd_path(char *cmd, char **path)
{
    char **tmp_path;
    char *cmd_path;

    tmp_path = path;
    while (*tmp_path)
    {
        cmd_path = ft_strjoin(*tmp_path, cmd);
        if (access(cmd_path, X_OK) == 0)
            return (cmd_path);
        ++tmp_path;
    }
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

t_arg init(char *file, char *cmd, char **envp)
{
    t_arg arg;
    char **paths;

    arg.file = file;
    paths = find_path(envp);
    arg.option = ft_split(cmd, ' ');
    arg.path = find_cmd_path(ft_strjoin("/", arg.option[0]), paths);
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
    // str_test("arg", arg.path);
    // str_test("arg2", arg.next->path);
    fork_and_exec(arg);
    while (wait((int *)0) != -1)
        ;
    return (0);
}