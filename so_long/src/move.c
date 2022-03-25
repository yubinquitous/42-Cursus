#include "../includes/so_long.h"

void    move_to_exit(t_param *param, int target_row, int target_col)
{
    t_game  *game;
    char    **map;
    void    *img;
    int     width;
    int     height;

    game = param->game;
    map = game->map;
    printf("collection : %d\n", game->collection);//test
    if (game->collection == 0)
        exit_game(param);
    img = mlx_xpm_file_to_image(param->mlx, "./asset/grass.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);    
    game->cur_row = target_row;
    game->cur_col = target_col;
    img = mlx_xpm_file_to_image(param->mlx, "./asset/Castle.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);
    img = mlx_xpm_file_to_image(param->mlx, "./asset/kirby64.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);
    printf("movement : %d\n", ++(game->n_move));
}

void    move_player(t_param *param, int target_row, int target_col)
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
    game->cur_row = target_row;
    game->cur_col = target_col;
    if (map[game->cur_row][game->cur_col] == 'C')
    {
        printf("COLLECT\n");
        --(game->collection);
        map[game->cur_row][game->cur_col] = '0';
        img = mlx_xpm_file_to_image(param->mlx, "./asset/grass.xpm", &width, &height);
        mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);
    }
    img = mlx_xpm_file_to_image(param->mlx, "./asset/kirby64.xpm", &width, &height);
    mlx_put_image_to_window(param->mlx, param->win, img, IMG_SIZE * game->cur_col, IMG_SIZE * game->cur_row);
}