/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:37:15 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 20:37:16 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/push_swap.h"

void rra(t_stack *a, int do_print)
{
    stack_push(a, a->data[a->tail]);
    a->tail = decrease_idx(a->tail, a->size);
    if (do_print)
        write(1, "rra\n", 4);
}

void rrb(t_stack *b, int do_print)
{
    stack_push(b, b->data[b->tail]);
    b->tail = decrease_idx(b->tail, b->size);
    if (do_print)
        write(1, "rrb\n", 4);
}

void rrr(t_dual_stack *ds, int do_print)
{
    rra(&(ds->a), 0);
    rrb(&(ds->b), 0);
    if (do_print)
        write(1, "rrr\n", 4);
}
