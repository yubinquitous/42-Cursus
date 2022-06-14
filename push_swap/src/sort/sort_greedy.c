#include "../../includes/push_swap.h"

void sort_by_pivot(t_dual_stack *ds, int num)
{
    if (num < ds->pivot_small)
    {
        pb(ds, 1);
        if (ds->pivot_small <= top(ds->a) && top(ds->a) <= ds->pivot_large)
            rr(ds, 1);
        else
            rb(&ds->b, 1);
    }
    else if (num > ds->pivot_large)
        pb(ds, 1);
    else
        ra(&(ds->a), 1);
}

void push_num_to_b(t_dual_stack *ds)
{
    int i;
    int num;
    int size;

    size = stack_size(ds->a, ds->size);
    i = increase_idx(ds->a.head, ds->size);
    while (size-- && stack_size(ds->a, ds->size) > 3)
        sort_by_pivot(ds, top(ds->a));
    while (stack_size(ds->a, ds->size) > 3)
        pb(ds, 1);
}

void update_sort(t_sort *sort, t_sort temp, t_dual_stack *ds)
{
    sort->a_idx = temp.a_idx;
    sort->b_idx = temp.b_idx;
    sort->command_min = temp.command_min;
    sort->flag = temp.flag;
    sort->a_num = ds->a.data[temp.a_idx];
    sort->b_num = ds->b.data[temp.b_idx];
}

void set_location_a(t_dual_stack *ds, t_sort *temp, int num)
{
    int left;
    int right;

    temp->a_idx = ds->a.head;
    while (temp->a_idx != ds->a.tail)
    {
        temp->a_idx = increase_idx(temp->a_idx, ds->size);
        if (temp->a_idx == ds->a.tail)
        {
            if (bottom(ds->a) < num && num < top(ds->a))
                temp->a_idx = increase_idx(ds->a.head, ds->size);
            else
                temp->a_idx = smallest_idx(ds->a);
            count_command(ds, temp);
            break;
        }
        left = ds->a.data[temp->a_idx];
        right = ds->a.data[increase_idx(temp->a_idx, ds->size)];
        if (left < num && num < right)
        {
            count_command(ds, temp);
            temp->a_idx = increase_idx(temp->a_idx, ds->size);
            break;
        }
    }
}

void push_num_to_a(t_dual_stack *ds)
{
    t_sort sort;
    t_sort temp;
    int b_stack_size;
    int num;

    b_stack_size = stack_size(ds->b, ds->size);
    temp.b_idx = increase_idx(ds->b.head, ds->size);
    sort.command_min = 2147483647;
    while (1)
    {
        num = ds->b.data[temp.b_idx];
        set_location_a(ds, &temp, num);
        if (temp.command_min < sort.command_min)
            update_sort(&sort, temp, ds);
        if (temp.b_idx == ds->b.tail)
            break;
        temp.b_idx = increase_idx(temp.b_idx, ds->size);
    }
    do_sort(ds, sort);
}

void sort_greedy(t_dual_stack *ds)
{
    push_num_to_b(ds);
    sort_three(&(ds->a));
    while (1)
    {
        if (stack_is_empty(ds->b))
            break;
        push_num_to_a(ds);
    }
    sort_a(&ds->a);
}