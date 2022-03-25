#include "../includes/so_long.h"

void	ft_free_map(t_game *game)
{
	int		i;
	char	**map;

	i = 0;
	map = game->map;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
	map = 0;
}

void	ft_free_param(t_param *param)
{
	free(param->game);
	param->game = 0;
	free(param);
	param = 0;
}
