#include "../includes/push_swap.h"
#include "../libft/libft.h"

void test(t_stack s)
{
    int test;
    test = -1;
    int i = increase_idx(s.head, s.size);
    printf("%d->%d\t", s.head, s.tail);
    while (i != increase_idx(s.tail, s.size))
    {
        printf("%d\t", s.data[i]);
        i = increase_idx(i, s.size);
    }
    printf("\n===========================================================\n");
}

int increase_idx(int i, int size)
{
    if (i == size)
        return (0);
    return (++i);
}

int decrease_idx(int i, int size)
{
    if (i == 0)
        return (size);
    return (--i);
}

int is_sorted(t_stack a)
{
    int i;
    int prev;

    i = increase_idx(a.head, a.size);
    prev = -2147483648;
    while (1)
    {
        // printf("left right : %d\t%d\n", prev, a.data[i]);
        if (a.data[i] < prev)
            return (0);
        prev = a.data[i];
        if (i == a.tail)
            break;
        i = increase_idx(i, a.size);
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
    test(ds.a);
    if (is_sorted(ds.a))
        return (0);
    sort(&ds);
    exit(0);
}