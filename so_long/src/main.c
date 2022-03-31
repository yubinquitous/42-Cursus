#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_param	*param;

	if (argc != 2)
	{
		printf("CHECK ARGC\n");
		system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");	//test
		return (0);
	}
	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
	{
		printf("PARAM MALLOC ERROR\n");
		system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");	//test
		exit(0);
	}
	if (!init_and_check(param, argv[1]))
	{
		ft_free_param(param);
		system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");	//test
		exit(0);
	}
	draw_game(param);
	mlx_hook(param->win, X_EVENT_KEY_PRESS, 0, &key_press, param);
	mlx_hook(param->win, X_EVENT_KEY_EXIT, 0, &key_exit, param);
	mlx_loop(param->mlx);
	return (0);
}
