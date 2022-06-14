/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:38:59 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 20:39:00 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
