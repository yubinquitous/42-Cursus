#include "../includes/push_swap.h"
#include "../libft/libft.h"

void test(t_dual_stack ds)
{
    int i = 0;
    while (i < ds.size)
    {
        printf("%d\n", ds.a.data[i]);
        ++i;
    }
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
    // test(ds);
    if (is_sorted(ds.a, ds.size))
        printf("SORTED\n");
    else
        printf("NOT SORTED\n");
    return (0);
}