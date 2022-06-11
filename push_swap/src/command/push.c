#include "../../includes/push_swap.h"

void pa(t_dual_stack *ds, int do_print)
{
    if (is_empty(ds->b))
        return;
    stack_push(&(ds->a), stack_pop(&(ds->b)));
    if (do_print)
        write(1, "pa\n", 3);
}

void pb(t_dual_stack *ds, int do_print)
{
    if (is_empty(ds->a))
        return;
    stack_push(&(ds->b), stack_pop(&(ds->a)));
    if (do_print)
        write(1, "pa\n", 3);
}