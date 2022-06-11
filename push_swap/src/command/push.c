#include "../../includes/push_swap.h"

// b의 top을 a의 top에 넣는다
void pa(t_dual_stack *ds, int do_print)
{
    if (is_empty(ds->b))
        return;
    stack_push(&(ds->a), stack_pop(&ds->b));
    if (do_print)
        write(1, "pa\n", 3);
}

void pb(t_dual_stack *ds, int do_print)
{
    if (is_empty(ds->a))
        return;
    stack_push(&(ds->b), stack_pop(&ds->a));
    if (do_print)
        write(1, "pa\n", 3);
}