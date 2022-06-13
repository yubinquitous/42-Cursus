#include "../includes/push_swap.h"

int stack_is_empty(t_stack s)
{
    return (s.head == s.tail);
}

int stack_is_sorted(t_stack a)
{
    int i;
    int prev;

    i = increase_idx(a.head, a.size);
    prev = -2147483648;
    while (1)
    {
        if (a.data[i] < prev)
            return (0);
        prev = a.data[i];
        if (i == a.tail)
            break;
        i = increase_idx(i, a.size);
    }
    return (1);
}

int stack_size(t_stack s, int cnt)
{
    int size;

    size = s.tail - s.head;
    if (size < 0)
        size = cnt + size + 1;
    return (size);
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