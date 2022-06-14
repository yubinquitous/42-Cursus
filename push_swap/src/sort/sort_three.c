/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:39:04 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 20:39:04 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

enum e_sort_three compare_three(int top, int middle, int bottom)
{
    enum e_sort_three order;

    if (middle < top && top < bottom)
        order = BAC;
    else if (bottom < middle && middle < top)
        order = CBA;
    else if (middle < bottom && bottom < top)
        order = CAB;
    else if (top < bottom && bottom < middle)
        order = ACB;
    else
        order = BCA;
    return (order);
}

void sort_three(t_stack *a)
{
    int order;
    int i;

    i = increase_idx(a->head, a->size);
    order = compare_three(a->data[i], a->data[increase_idx(i, a->size)], a->data[a->tail]);
    if (order == BAC)
        sa(a, 1);
    else if (order == CBA)
    {
        sa(a, 1);
        rra(a, 1);
    }
    else if (order == CAB)
        ra(a, 1);
    else if (order == ACB)
    {
        sa(a, 1);
        ra(a, 1);
    }
    else
        rra(a, 1);
}
