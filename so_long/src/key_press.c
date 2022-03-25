#include "../includes/so_long.h"

void    init_dir(int *dir_row, int *dir_col)
{
    dir_row[0] = -1;
    dir_row[1] = 1;
    dir_row[2] = 0;
    dir_row[3] = 0;
    dir_col[0] = 0;
    dir_col[1] = 0;
    dir_col[2] = -1;
    dir_col[3] = 1;
}

void    key_func(t_param *param, int dir)
{
    int     dir_row[4];
    int     dir_col[4];
    int     target_row;
    int     target_col;

    init_dir(dir_row, dir_col);
    target_row = param->game->cur_row + dir_row[dir];
    target_col = param->game->cur_col + dir_col[dir];
    if (param->game->map[target_row][target_col] != '1')
    {
        if (param->game->map[target_row][target_col] == 'E')
            move_to_exit(param, target_row, target_col);
        else
        {
            move_player(param, target_row, target_col);
        }
        printf("movement : %d\n", ++(param->game->n_move));
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
        key_func(param, 0);
    else if (keycode == KEY_S)
        key_func(param, 1);
    else if (keycode == KEY_A)
        key_func(param, 2);
    else if (keycode == KEY_D)
        key_func(param, 3);
    else ;
    return (0);
}