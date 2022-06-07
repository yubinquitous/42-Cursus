#include "../includes/push_swap.h"
#include "../libft/libft.h"

void test(t_dual_stack ds)
{
    int i = 0;
    while (i < ds.size)
        printf("%d\n", ds.a->data[i++]);
}

int main(int argc, char **argv)
{
    t_dual_stack ds;
    int cnt;

    if (argc < 2)
        error_exit();
    cnt = count_args(argc, argv);
    init_stack(argc, argv, cnt, &ds);
    test(ds);
    // while (!is_sort(ds) || !is_empty(ds))
    //     sort_stack(ds);
    return (0);
}