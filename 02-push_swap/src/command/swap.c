/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:37:20 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/15 13:38:13 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/push_swap.h"

void	sa(t_stack *a, int do_print)
{
	int	left;
	int	right;
	int	temp;

	left = increase_idx(a->head, a->size);
	right = increase_idx(left, a->size);
	temp = a->data[left];
	a->data[left] = a->data[right];
	a->data[right] = temp;
	if (do_print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int do_print)
{
	int	left;
	int	right;
	int	temp;

	left = increase_idx(b->head, b->size);
	right = increase_idx(left, b->size);
	temp = b->data[left];
	b->data[left] = b->data[right];
	b->data[right] = temp;
	if (do_print)
		write(1, "sb\n", 3);
}

void	ss(t_dual_stack *ds, int do_print)
{
	sa(&(ds->a), 0);
	sb(&(ds->b), 0);
	if (do_print)
		write(1, "ss\n", 3);
}
