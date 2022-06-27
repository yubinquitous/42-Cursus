/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:38:03 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/27 22:28:39 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

static int *init_stack_a_data(int argc, char **argv, int size)
{
	char **str;
	int *data;
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 1;
	data = (int *)malloc(sizeof(int) * (size + 1));
	if (!data)
		error_exit();
	data[0] = 0;
	while (++i < argc)
	{
		j = 0;
		str = ft_split(argv[i], ' ');
		if (!str)
			error_exit();
		while (str[j] && !is_duplicate(data, ft_atoi(str[j]), cnt))
			data[cnt++] = ft_atoi(str[j++]);
		free_all(str, j);
	}
	return (data);
}

static t_stack init_stack_a(int argc, char **argv, int size)
{
	t_stack a;

	a.data = init_stack_a_data(argc, argv, size);
	a.head = 0;
	a.tail = size;
	a.size = size;
	return (a);
}

static t_stack init_stack_b(int size)
{
	t_stack b;
	int i;

	i = -1;
	b.data = (int *)malloc(sizeof(int) * (size + 1));
	if (!b.data)
		error_exit();
	while (++i < size + 1)
		b.data[i] = 0;
	b.head = size;
	b.tail = size;
	b.size = size;
	return (b);
}

static void init_pivot(t_dual_stack *ds)
{
	int *sorted_data;

	sorted_data = data_cpy(ds->a.data, ds->a.size);
	bubble_sort(sorted_data, ds->a.size);
	ds->pivot_small = sorted_data[ds->a.size / 3 + 1];
	ds->pivot_large = sorted_data[ds->a.size * 2 / 3 + 1];
	free(sorted_data);
}

void init_stack(int argc, char **argv, int size, t_dual_stack *ds)
{
	ds->a = init_stack_a(argc, argv, size);
	ds->b = init_stack_b(size);
	init_pivot(ds);
}
