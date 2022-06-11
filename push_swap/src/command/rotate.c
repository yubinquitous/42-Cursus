#include "../../includes/push_swap.h"

// a의 모든 원소를 위로 1만큼 올린다.
void ra(t_stack *a, int do_print)
{
    a->tail = increase_idx(a->tail, a->size);
    a->data[a->tail] = stack_pop(a);
    if (do_print)
        write(1, "ra\n", 3);
}

void rb(t_stack *b, int do_print)
{
    b->tail = increase_idx(b->tail, b->size);
    b->data[b->tail] = stack_pop(b);
    if (do_print)
        write(1, "rb\n", 3);
}

void rr(t_dual_stack *ds, int do_print)
{
    ra(&(ds->a), 0);
    rb(&(ds->b), 0);
    if (do_print)
        write(1, "rr\n", 3);
}