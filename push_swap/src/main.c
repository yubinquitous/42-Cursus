#include "../includes/push_swap.h"
#include "../libft/libft.h"

void test(t_dual_stack ds)
{
    int i = 0;
    while (i < ds.size)
        printf("%d\n", ds.a->data[i++]);
}

int increase_idx(int i, int size)
{
    ++i;
    if (i == size)
        return (0);
    return (i);
}

int is_sorted(t_stack *a, int size)
{
    int i;
    int prev;

    i = a->head;
    while (i != a->tail)
    {
        if (prev > a->data[i])
            return (0);
        prev = a->data[i];
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
    printf("head : %d\n", ds.a->head);
    printf("tail : %d\n", ds.a->tail);
    test(ds);
    if (is_sorted(ds.a, ds.size))
        printf("SORTED\n");
    else
        printf("NOT SORTED\n");
    // while (!is_sorted(ds) || !is_empty(ds))
    //     sort_stack(ds);
    return (0);
}