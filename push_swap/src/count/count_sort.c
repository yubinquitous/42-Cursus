/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:37:36 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/14 21:16:58 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	select_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	compare_up_down(int uu, int ud, int du, int dd, t_sort *temp)
{
	if (uu < ud && uu < du && uu < dd)
	{
		temp->command_min = uu;
		temp->flag = UU;
	}
	else if (ud < uu && ud < du && ud < dd)
	{
		temp->command_min = ud;
		temp->flag = UD;
	}
	else if (du < uu && du < ud && du < dd)
	{
		temp->command_min = du;
		temp->flag = DU;
	}
	else
	{
		temp->command_min = dd;
		temp->flag = DD;
	}
}

int	count_up(t_stack s, int idx)
{
	int	length;
	int	size;

	size = stack_size(s, s.size);
	if (s.head < idx)
		length = idx - s.head - 1;
	else
		length = idx + s.size - s.head;
	return (length);
}

int	count_down(t_stack s, int idx)
{
	int	length;
	int	size;

	size = stack_size(s, s.size);
	length = size - count_up(s, idx) + 1;
	return (length);
}

void	count_command(t_dual_stack *ds, t_sort *temp)
{
	int	uu;
	int	ud;
	int	du;
	int	dd;

	uu = select_bigger(
			count_up(ds->a, temp->a_idx), count_up(ds->b, temp->b_idx));
	ud = count_up(ds->a, temp->a_idx) + count_down(ds->b, temp->b_idx);
	du = count_down(ds->a, temp->a_idx) + count_up(ds->b, temp->b_idx);
	dd = select_bigger(
			count_down(ds->a, temp->a_idx), count_down(ds->b, temp->b_idx));
	compare_up_down(uu, ud, du, dd, temp);
}
