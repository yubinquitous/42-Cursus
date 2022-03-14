#include "../includes/so_long.h"

int check_filename(char  *file_name)
{
    int     length;
    char    *s;

    length = 0;
    s = file_name;
    while (*s)
    {
        ++length;
        ++s;
    }
    if (length < 4 ||  file_name[length - 4] != '.' || file_name[length-3] != 'b' 
        || file_name[length - 2] != 'e' || file_name[length - 1] != 'r')
        return (0);
    else
        return (1);
}

void    count_cols(t_param *param, char *line)
{
    int     cols;
    char    *ptr;
    
    cols = 0;
    ptr = line;
    while (*ptr)
    {
        ++cols;
        ++ptr;
    }
    param->game = (t_game *)malloc(sizeof(t_game));
    param->game->n_col = cols;
}

int count_rows(t_param *param, int fd)
{
    char    *line;
    int     rows;

    rows = 0;
    line = get_next_line(fd);
    count_cols(param, line);
    while (!line)
    {
        line = get_next_line(fd);
        ++rows;
    }
    param->game->n_row = rows;
    param->game->map = (char **)malloc(rows * sizeof(char *));
    if (!(param->game->map))
        return (0);
    else
        return (1);
}

int save_line_to_map(t_param *param, char *line, int row)
{
    int i;
    int n_col;

    i = 0;
    n_col = param->game->n_col;
    param->game->map[row] = (char *)malloc(n_col * sizeof(char));
    while (line[i])
    {
        if ((row == 0 || row == n_col - 1) && line[i] != '1')
            return (0);
        param->game->map[row][i] = line[i];
        ++i;
    }
    return (1);
}

int check_map(t_param *param, int fd)
{
    char    *line;
    int     i;
    int     j;

    i = 0;
    while (i < param->game->n_row)
    {
        line = get_next_line(fd);
        save_line_to_map(param, line, i);
        ++i;
    }
}

int read_map(t_param *param, char *file_name)
{
    int     fd;
    int     ret;

    fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        return (0);
    }
    if (!(count_rows(param, fd)) || !(check_map(param, fd)))
    {
        // param->game->map 메모리 해제해주기
        ret = 0;
    }
    else
        ret = 1;
    // test
    int i = 0;
    while (i < 5) {
        write(1, param->game->map[i], param->game->n_col);
        ++i;
    }
    close(fd);
    return (ret);
}

int main(int argc, char *argv[])
{
    t_param *param;

    param = malloc(sizeof(t_param));
    if (argc != 2 || !param)
    {
        perror("Error\n");
        return (0);
    }
    
    /* check_argv */
    /* 1. check_filename */
    if (!check_filename(argv[1]))
    {
        perror("Error\n");
        free(param);
        return (0);
    }
    /* 2. read_map */
    if (!read_map(param, argv[1]))
    {
        perror("Error\n");
        free(param);
        return (0);
    }

    return (0);
}