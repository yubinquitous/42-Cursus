/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:38:54 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 20:49:48 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_five(t_dual_stack *ds)
{
	t_sort	sort;

	while (stack_size(ds->a, ds->a.size) > 3)
		pb(ds, 1);
	sort_three(&ds->a);
	while (!stack_is_empty(ds->b))
		push_num_to_a(ds);
	sort_a(&ds->a);
}
