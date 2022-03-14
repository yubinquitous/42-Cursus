#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_beta/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> //test

typedef struct s_game
{
    char    **map;
    int     n_col;
    int     n_row;
    int     cur_x;
    int     cur_y;
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