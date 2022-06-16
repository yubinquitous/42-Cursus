/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:35:38 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/16 21:45:00 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	top(t_stack s)
{
	return (s.data[increase_idx(s.head, s.size)]);
}

int	bottom(t_stack s)
{
	return (s.data[s.tail]);
}

int	main(int argc, char **argv)
{
	t_dual_stack	ds;
	int				cnt;

	if (argc < 2)
		return (0);
	cnt = count_args(argc, argv);
	init_stack(argc, argv, cnt, &ds);
	if (stack_is_sorted(ds.a))
		return (0);
	sort(&ds);
	return (0);
}
