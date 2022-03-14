#include "../includes/so_long.h"

void    ft_free_map(char **map)
{

}

void    ft_free_param(t_param *param)
{
    /* param 관련 전부 free */
}

void    count_rows(t_game *game, int fd)
{
    char    *line;
    int     rows;

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

void    create_map(t_game *game, int fd)
{
    int i;
    char    **map;

    i = 0;
    map = game->map;
    while (i < game->n_row)
    {
        map[i] = get_next_line(fd);
        ++i;
    }
}

int read_map(t_game *game, char *file_name)
{
    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return (0);
    count_rows(game, fd);
    close(fd);
    if (game->n_row == 0)
        return (0);
    game->map = (char **)malloc(game->n_row * sizeof(char *));
    if (!(game->map))
        return (0);
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        free(game->map);
        return (0);
    }
    create_map(game, fd);
    return (1);
}

int check_row(t_game *game, t_flag *flag, int cur_row)
{
    char    *line;
    int     i;

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
            game->cur_x = i;
            game->cur_y = cur_row;
        }
        else if (line[i] != '0' && line[i] != '1')
            return (0);
        ++i;
    }
    return (1);
}

int check_wall(char *line, int cur_row, int n_row, int n_col)
{
    int i;

    i = 0;
    printf("length : %d\n", ft_strlen(line));   //test
    printf("%s\n", line);
    while (line[i])
    {
        if (cur_row == 0 || cur_row == n_row - 1 || i == 0 || i == n_col - 1)
        {
            if (line[i] != '1')
            {
                printf("new line error. line[i] = %c\n", line[i]);//test
                return (0);
            }
        }
        ++i;
    }
    return (1);
}

// 맵 읽어서 game->map에 저장까진 한 상태. 이건 map 유효성 체크
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
        {
            printf("check_wall check_row error\n"); //test
            return (0);
        }
        ++i;
    }
    if (flag.c_flag == 0 || flag.e_flag == 0|| flag.p_flag != 1)
    {
        printf("flag error\n");
        return (0);
    }
    printf("c: %d, e: %d, p: %d\n", flag.c_flag, flag.e_flag, flag.p_flag); //test
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
    if (length < 4 && file_name[length - 4] != '.' || file_name[length-3] != 'b'
        || file_name[length - 2] != 'e' || file_name[length - 1] != 'r')
        return (0);
    else
    {
        if (!read_map(game, file_name))
        {
            return (0);
        }
        /* test => 맵 읽고 저장 성공*/
        // int i = 0;
        // while (i < game->n_row)
        // {
        //     printf("%s", game->map[i]);
        //     ++i;
        // }
        if (!check_map(game))
        {
            ft_free_map(game->map);
            return (0);
        }
        return (1);
    }
}

int init_and_check(t_param *param, char *file_name)
{
    param->game = (t_game *)malloc(sizeof(t_game));
    if (!(param->game))
        return (0);
    if (!check_file_name(param->game, file_name))
        return (0);
    return (1);
}

int main(int argc, char *argv[])
{
    t_param *param;

    param = (t_param *)malloc(sizeof(t_param));
    if (argc != 2 || !param)
    {
        perror("Error\n");
        return (0);
    }
    if (!init_and_check(param, argv[1]))
    {
        perror("Error\n");
        ft_free_param(param);
        return (0);
    }

    return (1);
}