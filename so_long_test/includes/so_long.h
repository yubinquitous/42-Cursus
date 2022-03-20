#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_beta/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> //test

# define IMG_SIZE   64
# define KEY_ESC    53
# define KEY_W      13
# define KEY_A      0
# define KEY_S      1
# define KEY_D      2

# define X_EVENT_KEY_PRESS  2
# define X_EVENT_KEY_EXIT   17

typedef struct s_game
{
    char    **map;
    int     n_col;
    int     n_row;
    int     n_move;
    int     cur_row;
    int     cur_col;
    int     collection;
}   t_game;

typedef struct s_flag
{
    int c_flag;
    int e_flag;
    int p_flag;
} t_flag;


typedef struct s_param
{
    void    *mlx;
    void    *win;
    t_game    *game;
}   t_param;

#endif
