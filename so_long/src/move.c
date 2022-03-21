#include "../includes/so_long.h"

void    move_to_exit(t_param *param, int *cur, int move)
{
    t_game  *game;
    char    **map;
    void    *img;
    int     width;
    int     height;

    game = param->game;
    map = game->map;
    printf("collection : %d\n", game->collection);
    if (game->collection == 0)
        exit_game(param);
    img = mlx_xpm_file_to_image(param->mlx, "./asset/grass.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);    
    *cur = move;
    img = mlx_xpm_file_to_image(param->mlx, "./asset/Castle.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);
    img = mlx_xpm_file_to_image(param->mlx, "./asset/kirby64.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);
    ft_putstr_fd("movement : ", 1);
    ft_putnbr_fd(++(game->n_move), 1);
    ft_putchar_fd('\n', 1);
}

void    move_player(t_param *param, int *cur, int move)
{
    t_game  *game;
    void    *img;
    int     width;
    int     height;
    char    **map;

    game = param->game;
    map = game->map;
    if (map[game->cur_row][game->cur_col] == 'E')
        img = mlx_xpm_file_to_image(param->mlx, "./asset/Castle.xpm", &width, &height);
    else
        img = mlx_xpm_file_to_image(param->mlx, "./asset/grass.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);
    *cur = move;
    img = mlx_xpm_file_to_image(param->mlx, "./asset/kirby64.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);
}