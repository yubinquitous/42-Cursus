#include "../includes/so_long.h"

void ft_free_map(t_game *game)
{
    int i;
    char    **map;

    i = game->n_row;
    map = game->map;
    while (i--)
    {
        free(map[i]);
        map[i] = 0;
    }
    free(map);
    map = 0;
}

void ft_free_param(t_param *param)
{
    free(param->game);
    param->game = 0;
    free(param);
    param = 0;
}

void count_rows(t_game *game, int fd)
{
    char *line;
    int rows;

    line = get_next_line(fd);
    rows = 0;
    while (line)
    {
        ++rows;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    game->n_row = rows;
}

int main(int argc, char *argv[])
{
    t_param *param;

    param = (t_param *)malloc(sizeof(t_param));
    if (argc != 2 || !param)
    {
        printf("argc, param error\n");  //test
        perror("Error\n");
        return (0);
    }
    if (!init_and_check(param, argv[1]))
    {
        printf("init_and_check error\n");   //test
        perror("Error\n");
        ft_free_param(param);
        return (0);
    }
    init_game(param);
    draw_game(param);
    mlx_hook(param->win, X_EVENT_KEY_PRESS, 0, &key_press, param);
    mlx_hook(param->win, X_EVENT_KEY_EXIT, 0, &key_exit, param);
    mlx_loop(param->mlx);
    return (0);
}