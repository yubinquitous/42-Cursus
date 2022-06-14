#include "../../includes/push_swap.h"

void do_uu(t_dual_stack *ds, t_sort sort)
{
    while (top(ds->a) != sort.a_num && top(ds->b) != sort.b_num)
        rr(ds, 1);
    while (top(ds->a) != sort.a_num)
        ra(&ds->a, 1);
    while (top(ds->b) != sort.b_num)
        rb(&ds->b, 1);
    pa(ds, 1);
}

void do_ud(t_dual_stack *ds, t_sort sort)
{
    while (top(ds->a) != sort.a_num)
        ra(&ds->a, 1);
    while (top(ds->b) != sort.b_num)
        rrb(&ds->b, 1);
    pa(ds, 1);
}

void do_du(t_dual_stack *ds, t_sort sort)
{
    while (top(ds->a) != sort.a_num)
        rra(&ds->a, 1);
    while (top(ds->b) != sort.b_num)
        rb(&ds->b, 1);
    pa(ds, 1);
}

void do_dd(t_dual_stack *ds, t_sort sort)
{
    while (top(ds->a) != sort.a_num && top(ds->b) != sort.b_num)
        rrr(ds, 1);
    while (top(ds->a) != sort.a_num)
        rra(&ds->a, 1);
    while (top(ds->b) != sort.b_num)
        rrb(&ds->b, 1);
    pa(ds, 1);
}

void do_sort(t_dual_stack *ds, t_sort sort)
{
    if (sort.flag == UU)
        do_uu(ds, sort);
    else if (sort.flag == UD)
        do_ud(ds, sort);
    else if (sort.flag == DU)
        do_du(ds, sort);
    else
        do_dd(ds, sort);
}