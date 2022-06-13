#include "../../includes/push_swap.h"

void sort_five(t_dual_stack *ds)
{
    t_sort sort;

    while (stack_size(ds->a, ds->size) > 3)
        pb(ds, 1);
    sort_three(&ds->a);
    while (!stack_is_empty(ds->b))
    {
        set_location_a(ds, &sort, top(ds->b));
        sort.a_num = ds->a.data[sort.a_idx];
        while (top(ds->a) != sort.a_num)
        {
            if (sort.command_min == UD || sort.command_min == UU)
                ra(&ds->a, 1);
            else
                rra(&ds->a, 1);
        }
        pa(ds, 1);
    }
    sort_a(&ds->a);
}