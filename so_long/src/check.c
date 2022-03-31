#include "../includes/so_long.h"

void	check_row(t_game *game, t_flag *flag, int cur_row)
{
	char	*line;
	int		i;

	line = game->map[cur_row];
	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			++(flag->c_flag);
		else if (line[i] == 'E')
			++(flag->e_flag);
		else if (line[i] == 'P')
		{
			++(flag->p_flag);
			game->cur_col = i;
			game->cur_row = cur_row;
		}
		else if (line[i] != '0' && line[i] != '1')
			ft_exit("MAP ERROR");
		++i;
	}
	if (i != game->n_col)
		ft_exit("MAP MUST BE RECTANGULAR");
}

void	check_wall(char *line, int cur_row, int n_row, int n_col)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((cur_row == 0 || cur_row == n_row - 1 || i == 0 || i == n_col - 1)
			&& (line[i] != '1'))
			ft_exit("MAP MUST BE SURRONDED BY WALLS");
		++i;
	}
}

void	check_map(t_game *game)
{
	t_flag	flag;
	int		i;

	flag.c_flag = 0;
	flag.e_flag = 0;
	flag.p_flag = 0;
	game->n_col = ft_strlen(game->map[0]);
	i = 0;
	while (i < game->n_row)
	{
		check_wall(game->map[i], i, game->n_row, game->n_col);
		check_row(game, &flag, i);
		++i;
	}
	if (flag.c_flag == 0 || flag.e_flag == 0 || flag.p_flag != 1)
		ft_exit("MAP MUST HAVE AT LEAST ONE ELEMENT");
	game->collection = flag.c_flag;
}

void	check_file_name(char *file)
{
	char	*ptr;
	int		length;

	ptr = file;
	length = 0;
	while (*ptr)
	{
		++length;
		++ptr;
	}
	if (length < 4 || file[length - 4] != '.' || file[length - 3] != 'b'
		|| file[length - 2] != 'e' || file[length - 1] != 'r')
		ft_exit("WRONG FILE NAME");
}
