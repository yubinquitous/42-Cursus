#include "../includes/so_long.h"

int init_and_check(t_param *param, char *file_name)
{
    param->game = (t_game *)malloc(sizeof(t_game));
    if (!(param->game))
        return (0);
    if (!check_file_name(param->game, file_name))
        return (0);
    return (1);
}

void    init_game(t_param *param)
{
    param->mlx = mlx_init();
    param->win = mlx_new_window(param->mlx, IMG_SIZE * (param->game->n_col), IMG_SIZE * (param->game->n_row), "yubin");
    param->game->n_move = 0;
}