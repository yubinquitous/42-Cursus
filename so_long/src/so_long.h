#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_param
{
    void    *mlx;
    void    *win;
    t_game    *game;
}   t_param;

typedef struct s_game
{
    char    **map;
    int     n_col;
    int     n_row;
    int     cur_x;
    int     cur_y;
    int     collection;
}   t_game;

#endif