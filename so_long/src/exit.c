#include "../includes/so_long.h"

void	exit_game(t_param *param)
{
	t_game	*game;

	game = param->game;
	printf("MOVEMENT : %d\n", ++(game->n_move));
	printf("---------\nCOMPLETE!\n---------\n");
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

int	key_exit(t_param *param)
{
	printf("--------\nGAME END\n--------\n");
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

void	ft_exit(char *msg)
{
	printf("ERROR\n");
	printf("%s\n", msg);
	exit(1);
}
