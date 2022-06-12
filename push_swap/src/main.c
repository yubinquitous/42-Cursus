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
    int stack_size_a;
    int i;
    int cnt;
    int prev;

    stack_size_a = stack_size(a, a.size);
    // printf("stack_size_a: %d\n", stack_size_a);
    i = smallest_idx(a);
    cnt = -1;
    prev = -2147483648;
    // printf("smallest idx : %d %d\n", a.data[i], i);
    while (stack_size_a--)
    {
        if (a.data[i] < prev)
            return (0);
        prev = a.data[i];
        // printf("prev : %d\n", prev);
        i = increase_idx(i, a.size);
    }
    // printf("SORTED\n");
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
    if (is_sorted(ds.a))
        return (0);
    sort(&ds);
    exit(0);
}