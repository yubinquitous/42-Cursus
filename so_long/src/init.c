#include "../includes/so_long.h"

int init_and_check(t_param *param, char *file_name)
{
    param->game = (t_game *)malloc(sizeof(t_game));
    if (!(param->game))
        return (0);
    init_param(param);
    if (!check_file_name(param->game, file_name))
        return (0);
    return (1);
}

void    init_param(t_param *param)
{
    param->mlx = mlx_init();
    param->game->n_move = 0;
    param->game->n_row = 0;
    param->game->n_col = 0;
}

int save_map(t_game *game, int fd)
{
    char    *line;
    char    *save;
    char    *temp;
    int     rows;

    save = ft_strdup("");
    rows = 0;
    line = get_next_line(fd);
    while (line)
    {
        ++rows;
        temp = ft_strjoin(save, line);
        free(line);
        if (!temp)
            return (0);
        free(save);
        save = temp;
        line = get_next_line(fd);
    }
    game->n_row = rows;
    game->map = ft_split(save, '\n');
    free(save);
    if (!(game->map))
        return (0);
    return (1);
}

int read_map(t_game *game, char *file_name)
{
    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return (0);
    if (!save_map(game, fd) || game->n_row == 0 || !(game->map))
        return (0);
    close(fd);
    return (1);
}