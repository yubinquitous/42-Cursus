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
    printf("\n");
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

    if (a.head == a.tail)
        return (0);
    i = increase_idx(a.head, a.size);
    prev = -2147483648;
    while (i != increase_idx(a.tail, a.size))
    {
        if (a.data[i] < prev)
            return (0);
        prev = a.data[i];
        i = increase_idx(i, a.size);
    }
    printf("sorted\n");
    test(a);
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
    if (is_sorted(ds.a))
        return (0);
    sort(&ds);
    return (0);
}