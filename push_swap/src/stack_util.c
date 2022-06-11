#include "../includes/push_swap.h"

int is_empty(t_stack s)
{
    if (s.head == s.tail)
        return (1);
    return (0);
}

void stack_push(t_stack *s, int num)
{
    s->head = decrease_idx(s->head, s->size);
    s->data[s->head] = num;
}

int stack_pop(t_stack *s)
{
    int num;

    num = s->data[s->head];
    s->head = increase_idx(s->head, s->size);
    return num;
}