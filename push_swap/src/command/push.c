/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:36:59 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 20:37:00 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/push_swap.h"

void pa(t_dual_stack *ds, int do_print)
{
    if (stack_is_empty(ds->b))
        return;
    stack_push(&(ds->a), stack_pop(&(ds->b)));
    if (do_print)
        write(1, "pa\n", 3);
}

void pb(t_dual_stack *ds, int do_print)
{
    stack_push(&(ds->b), stack_pop(&(ds->a)));
    if (do_print)
        write(1, "pb\n", 3);
}
