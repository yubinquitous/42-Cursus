#include "../includes/so_long.h"

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

void    draw_game_element(t_param *param, int row, int col)
{
    char    position;
    void    *img;
    int     width;
    int     height;

    position = param->game->map[row][col];
    img = mlx_xpm_file_to_image(param->mlx, "./asset/grass.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * col, IMG_SIZE * row);
    if (position == '0')
        return ;
    else if (position == '1')
        img = mlx_xpm_file_to_image(param->mlx, "./asset/tree.xpm", &width, &height);
    else if (position == 'C')
        img = mlx_xpm_file_to_image(param->mlx, "./asset/star.xpm", &width, &height);
    else if (position == 'E')
        img = mlx_xpm_file_to_image(param->mlx, "./asset/castle.xpm", &width, &height);
    else
        img = mlx_xpm_file_to_image(param->mlx, "./asset/kirby64.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * col, IMG_SIZE * row);
}

void    draw_game(t_param *param)
{
    int i;
    int j;
    int n_row;
    int n_col;
    
    i = 0;
    n_row = param->game->n_row;
    n_col = param->game->n_col;
    param->win = mlx_new_window(param->mlx, IMG_SIZE * (param->game->n_col), IMG_SIZE * (param->game->n_row), "yubin");
    while (i < n_row)
    {
        j = 0;
        while (j < n_col)
        {
            draw_game_element(param, i, j);
            ++j;
        }
        ++i;
    }
}