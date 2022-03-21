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