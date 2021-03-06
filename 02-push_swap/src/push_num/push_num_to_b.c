/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_num_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:38:31 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/15 20:38:40 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_by_pivot(t_dual_stack *ds, int num)
{
	if (num < ds->pivot_small)
	{
		pb(ds, 1);
		if (ds->pivot_small <= top(ds->a) && top(ds->a) <= ds->pivot_large)
			rr(ds, 1);
		else
			rb(&ds->b, 1);
	}
	else if (num > ds->pivot_large)
		pb(ds, 1);
	else
		ra(&(ds->a), 1);
}

void	push_num_to_b(t_dual_stack *ds)
{
	int	size;

	size = stack_size(ds->a, ds->a.size);
	while (size-- && stack_size(ds->a, ds->a.size) > 3)
		sort_by_pivot(ds, top(ds->a));
	while (stack_size(ds->a, ds->a.size) > 3)
		pb(ds, 1);
}
