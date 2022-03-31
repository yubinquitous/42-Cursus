#include "../includes/so_long.h"

void	move_to_exit(t_param *param, int target_row, int target_col)
{
	t_game	*game;
	char	**map;

	game = param->game;
	map = game->map;
	if (game->collection == 0)
		exit_game(param);
	ft_draw_image(param, "./asset/grass.xpm", game->cur_row, game->cur_col);
	game->cur_row = target_row;
	game->cur_col = target_col;
	ft_draw_image(param, "./asset/Castle.xpm", game->cur_row, game->cur_col);
	ft_draw_image(param, "./asset/kirby64.xpm", game->cur_row, game->cur_col);
	printf("movement : %d\n", ++(game->n_move));
}

void	move_player(t_param *param, int target_row, int target_col)
{
	t_game	*game;
	char	**map;

	game = param->game;
	map = param->game->map;
	if (map[game->cur_row][game->cur_col] == 'E')
		ft_draw_image(param, "./asset/Castle.xpm", game->cur_row, game->cur_col);
	else
		ft_draw_image(param, "./asset/grass.xpm", game->cur_row, game->cur_col);
	game->cur_row = target_row;
	game->cur_col = target_col;
	if (map[game->cur_row][game->cur_col] == 'C')
	{
		printf("COLLECT\n");
		--(game->collection);
		map[game->cur_row][game->cur_col] = '0';
		ft_draw_image(param, "./asset/grass.xpm", game->cur_row, game->cur_col);
	}
	ft_draw_image(param, "./asset/kirby64.xpm", game->cur_row, game->cur_col);
}
