#include "../includes/so_long.h"

void    exit_game(t_param *param)
{
    t_game  *game;

    game = param->game;
    ft_putstr_fd("movement : ", 1);
    ft_putnbr_fd(++(game->n_move), 1);
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("COMPLETE\n", 1);
    mlx_destroy_window(param->mlx, param->win);
    exit(0);
}

int key_exit(t_param *param)
{
    mlx_destroy_window(param->mlx, param->win);
    exit(0);
}