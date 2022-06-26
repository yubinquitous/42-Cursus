/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:37:50 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/26 23:32:45 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int increase_idx(int i, int size)
{
	if (i == size)
		return (0);
	return (++i);
}

int decrease_idx(int i, int size)
{
	if (i == 0)
		return (size);
	return (--i);
}

int smallest_idx(t_stack s)
{
	int i;
	int idx;
	int smallest;

	i = increase_idx(s.head, s.size);
	idx = i;
	smallest = INT_MAX;
	while (1)
	{
		if (smallest > s.data[i])
		{
			idx = i;
			smallest = s.data[i];
		}
		if (i == s.tail)
			break;
		i = increase_idx(i, s.size);
	}
	return (idx);
}

int biggest_idx(t_stack s)
{
	int i;
	int idx;
	int biggest;

	i = increase_idx(s.head, s.size);
	idx = i;
	biggest = INT_MIN;
	while (1)
	{
		if (biggest < s.data[i])
		{
			idx = i;
			biggest = s.data[i];
		}
		if (i == s.tail)
			break;
		i = increase_idx(i, s.size);
	}
	return (idx);
}
