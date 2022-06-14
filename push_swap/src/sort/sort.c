/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:38:44 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 20:38:45 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort(t_dual_stack *ds)
{
	if (ds->a.size == 2)
		sa(&ds->a, 1);
	else if (ds->a.size == 3)
		sort_three(&ds->a);
	else if (ds->a.size <= 5)
		sort_five(ds);
	else
		sort_greedy(ds);
}
