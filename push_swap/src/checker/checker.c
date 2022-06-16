/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:27:10 by yubin             #+#    #+#             */
/*   Updated: 2022/06/16 14:45:33 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/push_swap.h"
#include "../../libgnl/get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	if (i < n || s1[i])
		return (0);
	return (1);
}

static void	do_command(t_dual_stack *ds, char *command)
{
	if (ft_strncmp(command, "pa\n", 3))
		pa(ds, 0);
	else if (ft_strncmp(command, "pb\n", 3))
		pb(ds, 0);
	else if (ft_strncmp(command, "ra\n", 3))
		ra(&ds->a, 0);
	else if (ft_strncmp(command, "rb\n", 3))
		rb(&ds->b, 0);
	else if (ft_strncmp(command, "rr\n", 3))
		rr(ds, 0);
	else if (ft_strncmp(command, "rra\n", 4))
		rra(&ds->a, 0);
	else if (ft_strncmp(command, "rrb\n", 4))
		rrb(&ds->b, 0);
	else if (ft_strncmp(command, "rrr\n", 4))
		rrr(ds, 0);
	else if (ft_strncmp(command, "sa\n", 3))
		sa(&ds->a, 0);
	else if (ft_strncmp(command, "sb\n", 3))
		sb(&ds->b, 0);
	else if (ft_strncmp(command, "ss\n", 3))
		ss(ds, 0);
	else
		error_exit();
}

void	do_input(t_dual_stack *ds)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (!command || *command == '\n')
			break ;
		do_command(ds, command);
		free(command);
		command = 0;
	}
	if (stack_is_empty(ds->b) && stack_is_sorted(ds->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	do_input(&ds);
	return (0);
}
