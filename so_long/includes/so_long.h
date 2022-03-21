#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

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

void a_func(t_param *param);
int check_file_name(t_game *game, char *file_name);
int check_map(t_game *game);
int check_row(t_game *game, t_flag *flag, int cur_row);
int check_wall(char *line, int cur_row, int n_row, int n_col);
void count_rows(t_game *game, int fd);
void create_map(t_game *game, int fd);
void d_func(t_param *param);
void draw_game(t_param *param);
void draw_game_element(t_param *param, int row, int col);
void exit_game(t_param *param);
void ft_free_map(t_game *game);
void ft_free_param(t_param *param);
int init_and_check(t_param *param, char *file_name);
void init_game(t_param *param);
int key_exit(t_param *param);
int key_press(int keycode, t_param *param);
int main(int argc, char *argv[]);
void move_player(t_param *param, int *cur, int move);
void move_to_exit(t_param *param, int *cur, int move);
int read_map(t_game *game, char *file_name);
void s_func(t_param *param);
void w_func(t_param *param);

#endif
