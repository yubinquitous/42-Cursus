#include "../includes/push_swap.h"

int top(t_stack s)
{
    return (s.data[increase_idx(s.head, s.size)]);
}

int bottom(t_stack s)
{
    return (s.data[s.tail]);
}

int increase_idx(int i, int size)
{
    if (i == size)
        return (0);
    return (++i);
}

int decrease_idx(int i, int size)
{
    if (i == 0)
        return (size);
    return (--i);
}

int smallest_idx(t_stack s)
{
    int i;
    int idx;
    int smallest;

    i = increase_idx(s.head, s.size);
    smallest = 2147483647;
    while (1)
    {
        if (smallest > s.data[i])
        {
            idx = i;
            smallest = s.data[i];
        }
        if (i == s.tail)
            break;
        i = increase_idx(i, s.size);
    }
    return idx;
}

int biggest_idx(t_stack s)
{
    int i;
    int idx;
    int biggest;

    i = increase_idx(s.head, s.size);
    idx = i;
    biggest = -2147483648;
    while (1)
    {
        if (biggest < s.data[i])
        {
            idx = i;
            biggest = s.data[i];
        }
        if (i == s.tail)
            break;
        i = increase_idx(i, s.size);
    }
    return idx;
}