#include "../../includes/push_swap.h"

void sort_greedy(t_dual_stack *ds)
{
    sort_by_pivot(ds);
    sort_three(&(ds->a));
    while (1)
    {
        if (stack_is_empty(ds->b))
            break;
        push_num_to_a(ds);
    }
    sort_a(&ds->a);
}