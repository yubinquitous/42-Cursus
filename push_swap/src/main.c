/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:35:38 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/15 16:15:48 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

// void	test(t_stack s)
// {
// 	int i = increase_idx(s.head, s.size);
// 	printf("%d->%d\t", s.head, s.tail);
// 	while (i != increase_idx(s.tail, s.size))
// 	{
// 		printf("%d\t", s.data[i]);
// 		i = increase_idx(i, s.size);
// 	}
// 	printf("\n===========================================================\n");
// }

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
