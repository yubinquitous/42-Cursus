/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:38:48 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 20:38:49 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_a(t_stack *a)
{
    int smallest;
    int i;
    int length;

    i = smallest_idx(*a);
    smallest = a->data[i];
    length = count_up(*a, i);
    if (length < a->size / 2)
    {
        while (smallest != top(*a))
            ra(a, 1);
    }
    else
    {
        while (smallest != top(*a))
            rra(a, 1);
    }
}
