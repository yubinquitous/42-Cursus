#include "../includes/so_long.h"

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
    int     empty_width;
    int     empty_height;
    void    *empty_ptr;

    position = param->game->map[row][col];
    if (position == '0')
        img = mlx_xpm_file_to_image(param->mlx, "./asset/grass.xpm", &width, &height);
    else if (position == '1')
        img = mlx_xpm_file_to_image(param->mlx, "./asset/tree.xpm", &width, &height);
    else if (position == 'C')
        img = mlx_xpm_file_to_image(param->mlx, "./asset/star.xpm", &width, &height);
    else if (position == 'E')
        img = mlx_xpm_file_to_image(param->mlx, "./asset/castle.xpm", &width, &height);
    else 
        img = mlx_xpm_file_to_image(param->mlx, "./asset/kirby64.xpm", &width, &height);
    empty_ptr = mlx_xpm_file_to_image(param->mlx, "./asset/grass.xpm", &empty_width, &empty_height);
    mlx_put_image_to_window(param->mlx, param->win, empty_ptr, IMG_SIZE * col, IMG_SIZE * row);
    //printf("width : %d, height : %d", width, height);
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