#include "../includes/push_swap.h"
#include "../libft/libft.h"

void test(int size, int *data)
{
    int i = 0;
    while (i < size)
    {
        printf("%d\n", data[i]);
        ++i;
    }
    printf("---------------------\n");
}

int increase_idx(int i, int size)
{
    ++i;
    if (i == size)
        return (0);
    return (i);
}

int decrease_idx(int i, int size)
{
    --i;
    if (i == 0)
        return (size - 1);
    return (i);
}

int is_sorted(t_stack a, int size)
{
    int i;
    int prev;

    if (a.head == a.tail)
        return (0);
    i = a.head;
    prev = -2147483648;
    while (1)
    {
        if (prev > a.data[i])
            return (0);
        if (i == a.tail)
            break;
        prev = a.data[i];
        i = increase_idx(i, size);
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_dual_stack ds;
    int cnt;

    if (argc < 2)
        error_exit();
    cnt = count_args(argc, argv);
    init_stack(argc, argv, cnt, &ds);
    // test(ds.size, ds.a.data);
    // while (!is_sorted(ds.a, ds.size))
    //     ft_sort(&ds);
    if (is_sorted(ds.a, ds.size))
        return (0);
    ft_sort(&ds);
    return (0);
}