#include "../includes/so_long.h"

void	exit_game(t_param *param)
{
	t_game	*game;

	game = param->game;
	printf("movement : %d\n", ++(game->n_move));
	printf("COMPLETE\n");
	mlx_destroy_window(param->mlx, param->win);
	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");	//test
	exit(0);
}

int	key_exit(t_param *param)
{
	mlx_destroy_window(param->mlx, param->win);
	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");	//test
	exit(0);
}
