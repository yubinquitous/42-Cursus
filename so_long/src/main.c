#include "../includes/so_long.h"

void ft_free_map(char **map)
{
    /* game->map free */
}

void ft_free_param(t_param *param)
{
    /* param 전부 free */
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

void create_map(t_game *game, int fd)
{
    int i;
    char **map;

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
    if (ft_strlen(line) != n_col)
        return (0);
    while (line[i])
    {
        if (cur_row == 0 || cur_row == n_row - 1 || i == 0 || i == n_col - 1)
        {
            if (line[i] != '1')
            {
                printf("new line error. line[i] = %c\n", line[i]); // test
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
            printf("check_wall check_row error\n"); // test
            return (0);
        }
        ++i;
    }
    if (flag.c_flag == 0 || flag.e_flag == 0 || flag.p_flag != 1)
    {
        printf("flag error\n");
        return (0);
    }
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
    else
    {
        if (!read_map(game, file_name))
        {
            ft_free_map(game->map);
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

void    init_game(t_param *param)
{
    param->mlx = mlx_init();
    param->win = mlx_new_window(param->mlx, IMG_SIZE * (param->game->n_row), IMG_SIZE * (param->game->n_col), "yubin");
    param->game->n_move = 0;
}

void    draw_game_element(t_param *param, int row, int col)
{
    char    position;
    void    *img_ptr;
    int     width;
    int     height;

    position = param->game->map[row][col];
    if (position == '0')
        img_ptr = mlx_xpm_file_to_image(param->mlx, "./asset/grass.xpm", &width, &height);
    else if (position == '1')
        img_ptr = mlx_xpm_file_to_image(param->mlx, "./asset/tree.xpm", &width, &height);
    else if (position == 'C')
        img_ptr = mlx_xpm_file_to_image(param->mlx, "./asset/star.xpm", &width, &height);
    else if (position == 'E')
        img_ptr = mlx_xpm_file_to_image(param->mlx, "./asset/Castle.xpm", &width, &height);
    else {
        printf("position : %c\n", position);
        img_ptr = mlx_xpm_file_to_image(param->mlx, "./asset/kirby64.xpm", &width, &height);
    }
    //printf("width : %d, height : %d", width, height);
    mlx_put_image_to_window(param->mlx, param->win, img_ptr, IMG_SIZE * row, IMG_SIZE * col);
}

void    draw_game(t_param *param)
{
    int i;
    int j;
    int n_row;
    int n_col;
    
    i = 0;
    n_row = param->game->n_row;
    n_col = param->game->n_col;
    while (i < n_row)
    {
        j = 0;
        while (j < n_col)
        {
            draw_game_element(param, i, j);
            ++j;
        }
        ++i;
    }
    
}

int key_press(t_param *param, int keycode)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(param->mlx, param->win);
        exit(0);
    }
    // else if (keycode == KEY_W)
    //     move_w(param);
    // else if (keycode == KEY)
    return (0);
}

int key_exit(t_param *param)
{
    mlx_destroy_window(param->mlx, param->win);
    exit(0);
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
    init_game(param);
    draw_game(param);
    mlx_hook(param->win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
    mlx_hook(param->win, X_EVENT_KEY_EXIT, 0, &key_exit, &param);
    mlx_loop(param->mlx);
    return (0);
}