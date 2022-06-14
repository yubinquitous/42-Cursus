#include "../includes/push_swap.h"
#include "../libft/libft.h"

void test(t_stack s)
{
    int i = increase_idx(s.head, s.size);
    printf("%d->%d\t", s.head, s.tail);
    while (i != increase_idx(s.tail, s.size))
    {
        printf("%d\t", s.data[i]);
        i = increase_idx(i, s.size);
    }
    printf("\n===========================================================\n");
}

int top(t_stack s)
{
    return (s.data[increase_idx(s.head, s.size)]);
}

int bottom(t_stack s)
{
    return (s.data[s.tail]);
}

int main(int argc, char **argv)
{
    t_dual_stack ds;
    int cnt;

    if (argc < 2)
        return (0);
    cnt = count_args(argc, argv);
    init_stack(argc, argv, cnt, &ds);
    if (stack_is_sorted(ds.a))
        return (0);
    sort(&ds);
    // system("leaks push_swap > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
    return (0);
}