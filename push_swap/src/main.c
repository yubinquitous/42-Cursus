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

int main(int argc, char **argv)
{
    t_dual_stack ds;
    int cnt;

    if (argc < 2)
        error_exit();
    cnt = count_args(argc, argv);
    init_stack(argc, argv, cnt, &ds);
    if (stack_is_sorted(ds.a))
        return (0);
    sort(&ds);
    exit(0);
}