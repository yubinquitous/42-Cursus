#include "../../includes/push_swap.h"

// a의 모든 원소를 위로 1만큼 올린다.
void ra(t_stack *a, int do_print)
{
    int num;

    num = a->data[a->tail];
    a->tail = decrease_idx(a->tail, a->size);
    stack_push(a, num);
    if (do_print)
        write(1, "ra\n", 3);
}

void rb(t_stack *b, int do_print)
{
    int num;

    num = b->data[b->tail];
    b->tail = decrease_idx(b->tail, b->size);
    stack_push(b, num);
    if (do_print)
        write(1, "rb\n", 3);
}

void rra(t_stack *a, int do_print)
{
    int num;

    num = stack_pop(a);
    a->tail = increase_idx(a->tail, a->size);
    a->data[a->tail] = num;
    if (do_print)
        write(1, "rra\n", 3);
}

void rrb(t_stack *b, int do_print)
{
}