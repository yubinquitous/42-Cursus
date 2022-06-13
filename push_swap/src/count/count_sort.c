#include "../../includes/push_swap.h"

int count_up(t_stack s, int idx)
{
    int length;

    if (s.head < idx)
        length = idx - s.head - 1;
    else
        length = s.size - (s.head - idx);
    return length;
}

int count_down(t_stack s, int idx)
{
    int length;

    if (s.head < idx)
        length = s.size - idx + s.head + 2;
    else
        length = s.head - idx + 1;
    return length;
}

void count_command(t_dual_stack *ds, t_sort *temp)
{
    int uu;
    int ud;
    int du;
    int dd;

    uu = select_bigger(count_up(ds->a, temp->a_idx), count_up(ds->b, temp->b_idx));
    ud = count_up(ds->a, temp->a_idx) + count_down(ds->b, temp->b_idx);
    du = count_down(ds->a, temp->a_idx) + count_up(ds->b, temp->b_idx);
    dd = select_bigger(count_down(ds->a, temp->a_idx), count_down(ds->b, temp->b_idx));

    if (uu < ud && uu < du && uu < dd)
    {
        temp->command_min = uu;
        temp->flag = UU;
    }
    else if (ud < uu && ud < du && ud < dd)
    {
        temp->command_min = ud;
        temp->flag = UD;
    }
    else if (du < uu && du < ud && du < dd)
    {
        temp->command_min = du;
        temp->flag = DU;
    }
    else
    {
        temp->command_min = dd;
        temp->flag = DD;
    }
}