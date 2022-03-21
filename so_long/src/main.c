#include "../includes/so_long.h"

int main(int argc, char *argv[])
{
    t_param *param;

    if (argc != 2)
    {
        ft_putstr_fd("CHECK ARGC\n", 1);
        return (0);
    }
    param = (t_param *)malloc(sizeof(t_param));
    if (!param)
    {
        ft_putstr_fd("PARAM MALLOC ERROR\n", 1);
        return(0);
    }
    if (!init_and_check(param, argv[1]))
    {
        ft_free_param(param);
        return (0);
    }
    draw_game(param);
    mlx_hook(param->win, X_EVENT_KEY_PRESS, 0, &key_press, param);
    mlx_hook(param->win, X_EVENT_KEY_EXIT, 0, &key_exit, param);
    mlx_loop(param->mlx);
    // int *test;
    // test = malloc(4);
    return (0);
}