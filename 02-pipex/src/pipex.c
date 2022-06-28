#include "../include/pipex.h"
#include "../lib/libft/libft.h"

#include <stdio.h>
#include <unistd.h>

char *find_path(char **envp)
{
    int i;
    char *path;

    i = -1;
    while (envp[++i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            path = ft_strdup(envp[i] + 5);
            if (!path)
                error_exit("malloc error", 1);
            return (path);
        }
    }
    error_exit("PATH not found", 1);
    return (NULL);
}

void path_test(char *path)
{
    char **paths = ft_split(path, ':');
    while (*paths)
    {
        printf("%s\n", *paths);
        ++paths;
    }
}
void init(t_arg *arg, int argc, char **argv, char **envp)
{
    t_arg temp1;
    t_arg temp2;

    temp1.file = argv[1];
    temp1.cmd = ft_strjoin("/", argv[2]);
    temp2.cmd = ft_strjoin("/", argv[3]);
    temp2.file = argv[4];
    temp1.path = find_path(envp);
    temp2.path = temp1.path;
    // path_test(temp1.path);
}

void fork_and_exec(t_arg arg)
{
    int i;
    pid_t pid;
    t_arg tmp_arg;

    i = 2;
    tmp_arg = arg;
    while (i--)
    {
        pid = fork();
        if (pid == -1)
            error_exit("fork error", 1);
        // else if (pid == 0)
        //     do_child(arg);
        // else
        //     do_parent(arg);
        tmp_arg = *(tmp_arg.next);
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