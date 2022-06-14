/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_num_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:38:25 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 20:38:26 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
        temp->a_idx = increase_idx(temp->a_idx, ds->a.size);
        if (temp->a_idx == ds->a.tail)
        {
            if (bottom(ds->a) < num && num < top(ds->a))
                temp->a_idx = increase_idx(ds->a.head, ds->a.size);
            else
                temp->a_idx = smallest_idx(ds->a);
            count_command(ds, temp);
            break;
        }
        left = ds->a.data[temp->a_idx];
        right = ds->a.data[increase_idx(temp->a_idx, ds->a.size)];
        if (left < num && num < right)
        {
            count_command(ds, temp);
            temp->a_idx = increase_idx(temp->a_idx, ds->a.size);
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

    b_stack_size = stack_size(ds->b, ds->b.size);
    temp.b_idx = increase_idx(ds->b.head, ds->b.size);
    sort.command_min = 2147483647;
    while (1)
    {
        num = ds->b.data[temp.b_idx];
        set_location_a(ds, &temp, num);
        if (temp.command_min < sort.command_min)
            update_sort(&sort, temp, ds);
        if (temp.b_idx == ds->b.tail)
            break;
        temp.b_idx = increase_idx(temp.b_idx, ds->b.size);
    }
    do_sort(ds, sort);
}
