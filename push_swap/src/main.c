/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:35:38 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/16 21:28:15 by yubchoi          ###   ########.fr       */
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

#include <stdlib.h>
void	check_leaks(void)
{
	system("leaks push_swap");
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_dual_stack	ds;
	int				cnt;

	atexit(check_leaks);
	if (argc < 2)
		return (0);
	cnt = count_args(argc, argv);
	init_stack(argc, argv, cnt, &ds);
	if (stack_is_sorted(ds.a))
	{
		// printf("stack_is_sorted(ds.a)\n");
		// system("leaks push_swap");
		exit(0);
	}
	sort(&ds);
	// system("leaks push_swap");
	exit(0);
}
