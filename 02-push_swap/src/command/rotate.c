/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:37:03 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 21:04:38 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/push_swap.h"

void	ra(t_stack *a, int do_print)
{
	if (stack_size(*a, a->size) < 2)
		return ;
	a->tail = increase_idx(a->tail, a->size);
	a->data[a->tail] = stack_pop(a);
	if (do_print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int do_print)
{
	if (stack_size(*b, b->size) < 2)
		return ;
	b->tail = increase_idx(b->tail, b->size);
	b->data[b->tail] = stack_pop(b);
	if (do_print)
		write(1, "rb\n", 3);
}

void	rr(t_dual_stack *ds, int do_print)
{
	ra(&(ds->a), 0);
	rb(&(ds->b), 0);
	if (do_print)
		write(1, "rr\n", 3);
}
