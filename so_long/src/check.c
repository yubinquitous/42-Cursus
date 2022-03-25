#include "../includes/so_long.h"

int check_row(t_game *game, t_flag *flag, int cur_row)
{
    char *line;
    int i;

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
            return (0);
        ++i;
    }
    if (i != game->n_col)
        return (0);
    return (1);
}

int check_wall(char *line, int cur_row, int n_row, int n_col)
{
    int i;

    i = 0;
    while (line[i])
    {
        if ((cur_row == 0 || cur_row == n_row - 1 || i == 0 || i == n_col - 1) && (line[i] != '1'))
            return (0);
        ++i;
    }
    return (1);
}

int check_map(t_game *game)
{
    t_flag  flag;
    int     i;

    flag.c_flag = 0;
    flag.e_flag = 0;
    flag.p_flag = 0;
    game->n_col = ft_strlen(game->map[0]);
    i = 0;
    while (i < game->n_row)
    {
        if (!check_wall(game->map[i], i, game->n_row, game->n_col) || !check_row(game, &flag, i))
            return (0);
        ++i;
    }
    if (flag.c_flag == 0 || flag.e_flag == 0 || flag.p_flag != 1)
        return (0);
    game->collection = flag.c_flag;
    return (1);
}

int check_file_name(t_game *game, char *file_name)
{
    char    *ptr;
    int     length;

    ptr = file_name;
    length = 0;
    while (*ptr)
    {
        ++length;
        ++ptr;
    }
    if (length < 4 && file_name[length - 4] != '.' || file_name[length - 3] != 'b' || file_name[length - 2] != 'e' || file_name[length - 1] != 'r')
        return (0);
    if (!read_map(game, file_name))
		{
			printf("READING MAP ERROR\n");
            return (0);
		}
        if (!check_map(game))
        {
			printf("MAP ERROR\n");
            ft_free_map(game);
            return (0);
        }
    return (1);
}