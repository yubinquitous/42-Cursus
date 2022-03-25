#include "../includes/so_long.h"

void    w_func(t_param *param)
{
    t_game  *game;
    char    **map;

    game = param->game;
    map = param->game->map;
    if ((0 < game->cur_row - 1) &&  (map[game->cur_row -1][game->cur_col] != '1'))
    {
        if (map[game->cur_row -1][game->cur_col] == 'E')
        {
            move_to_exit(param, &(game->cur_row), game->cur_row - 1);
        } 
        else
        {
            move_player(param, &(game->cur_row), game->cur_row - 1);
            if (map[game->cur_row][game->cur_col] == 'C')
            {
                printf("COLLECT\n");
                --(game->collection);
                map[game->cur_row][game->cur_col] = '0';
            }
            printf("movement : %d\n", ++(game->n_move));
        }
    }
}

void    a_func(t_param *param)
{
    t_game  *game;
    char    **map;

    game = param->game;
    map = game->map;
    if ((0 < game->cur_col - 1) && (map[game->cur_row][game->cur_col - 1] != '1'))
    {
        if (map[game->cur_row][game->cur_col - 1] == 'E')
            move_to_exit(param, &(game->cur_col), game->cur_col - 1);
        else
        {
            move_player(param, &(game->cur_col), game->cur_col - 1);
            if (map[game->cur_row][game->cur_col] == 'C')
            {
                printf("COLLECT\n");
                --(game->collection);
                map[game->cur_row][game->cur_col] = '0';
            }
            printf("movement : %d\n", ++(game->n_move));
        }
    }
}

void    s_func(t_param *param)
{
    t_game  *game;
    char    **map;

    game = param->game;
    map = param->game->map;
    if ((game->cur_row + 1 < game->n_row - 1) &&  (map[game->cur_row + 1][game->cur_col] != '1'))
    {
        if (map[game->cur_row + 1][game->cur_col] == 'E')
        {
            move_to_exit(param, &(game->cur_row), game->cur_row + 1);
        } 
        else
        {
            move_player(param, &(game->cur_row), game->cur_row + 1);
            if (map[game->cur_row][game->cur_col] == 'C')
            {
                printf("COLLECT\n");
                --(game->collection);
                map[game->cur_row][game->cur_col] = '0';
            }
            printf("movement : %d\n", ++(game->n_move));
        }
    }
}

void    d_func(t_param *param)
{
    t_game  *game;
    char    **map;

    game = param->game;
    map = game->map;
    if ((game->cur_col + 1 < game->n_col - 1) && (map[game->cur_row][game->cur_col + 1] != '1'))
    {
        if (map[game->cur_row][game->cur_col + 1] == 'E')
            move_to_exit(param, &(game->cur_col), game->cur_col + 1);
        else
        {
            move_player(param, &(game->cur_col), game->cur_col + 1);
            if (map[game->cur_row][game->cur_col] == 'C')
            {
                printf("COLLECT\n");
                --(game->collection);
                map[game->cur_row][game->cur_col] = '0';
            }
            printf("movement : %d\n", ++(game->n_move));
        }
    }
}

int key_press(int keycode, t_param *param)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(param->mlx, param->win);
        exit(0);
    }
    else if (keycode == KEY_W)
        w_func(param);
    else if (keycode == KEY_A)
        a_func(param);
    else if (keycode == KEY_S)
        s_func(param);
    else if (keycode == KEY_D)
        d_func(param);
    else ;
    return (0);
}