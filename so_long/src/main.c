#include <so_long.h>

int main(int argc, char *argv[])
{
    t_param *param;

    param = malloc(sizeof(t_param));
    if (argc != 2 || !param)
    {
        perror("Error\n");
        return (0);
    }
    

    return (0);
}