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
# define KEY_S      1
# define KEY_A      0
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

int	check_file_name(t_game *game, char *file);
int	check_map(t_game *game);
int check_row(t_game *game, t_flag *flag, int cur_row);
int check_wall(char *line, int cur_row, int n_row, int n_col);
void count_rows(t_game *game, int fd);
int save_map(t_game *game, int fd);
void draw_game(t_param *param);
void draw_game_element(t_param *param, int row, int col);
void exit_game(t_param *param);
void ft_free_map(t_game *game);
void ft_free_param(t_param *param);
int init_and_check(t_param *param, char *file_name);
void init_param(t_param *param);
int key_exit(t_param *param);
int key_press(int keycode, t_param *param);
int main(int argc, char *argv[]);
void move_player(t_param *param, int target_row, int target_col);
void move_to_exit(t_param *param, int target_row, int target_col);
int read_map(t_game *game, char *file_name);
void	key_func(t_param *param, int changing_row, int changing_col);
void    init_dir(int *dir_row, int *dir_col);
void    ft_draw_image(t_param *param, char *img_path, int row, int col);
#endif
