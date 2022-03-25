#include "../includes/so_long.h"

void    exit_game(t_param *param)
{
    t_game  *game;

    game = param->game;
    printf("movement : %d\n", ++(game->n_move));
    printf("COMPLETE\n");
    mlx_destroy_window(param->mlx, param->win);
    exit(0);
}

int key_exit(t_param *param)
{
    mlx_destroy_window(param->mlx, param->win);
    exit(0);
}