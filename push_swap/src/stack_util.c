#include "../includes/push_swap.h"

int is_empty(t_stack s)
{
    if (s.head == increase_idx(s.tail, s.size))
        return (1);
    return (0);
}

void stack_push(t_stack *s, int num)
{
    s->data[s->head] = num;
    s->head = decrease_idx(s->head, s->size);
}

int stack_pop(t_stack *s)
{
    s->head = increase_idx(s->head, s->size);
    return (s->data[s->head]);
}