#include "../includes/so_long.h"

void count_rows(t_game *game, int fd)
{
    char *line;
    int rows;

    line = get_next_line(fd);
    rows = 0;
    while (line)
    {
        ++rows;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    game->n_row = rows;
}

void create_map(t_game *game, int fd)
{
    int i;
    char **map;

    i = 0;
    map = game->map;
    while (i < game->n_row)
    {
        map[i] = get_next_line(fd);
        ++i;
    }
}

int read_map(t_game *game, char *file_name)
{
    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return (0);
    count_rows(game, fd);
    close(fd);
    if (game->n_row == 0)
        return (0);
    game->map = (char **)malloc(game->n_row * sizeof(char *));
    if (!(game->map))
        return (0);
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        free(game->map);
        game->map = 0;
        return (0);
    }
    create_map(game, fd);
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