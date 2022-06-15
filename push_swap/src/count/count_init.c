/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:37:30 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/15 15:42:10 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

static int	count_argv(char *str)
{
	char	**temp;
	int		cnt;
	int		i;
	int		j;

	temp = ft_split(str, ' ');
	if (!temp)
		error_exit();
	cnt = 0;
	i = 0;
	while (temp && temp[i])
	{
		j = 0;
		while (temp[i] && temp[i][j])
		{
			if (!ft_isdigit(temp[i][j]) && !ft_issign(temp[i][j]))
				error_exit();
			++j;
		}
		++i;
		++cnt;
	}
	free_all(temp, i);
	return (cnt);
}

int	count_args(int argc, char **argv)
{
	int	i;
	int	args_cnt;
	int argv_cnt;

	i = 0;
	args_cnt = 0;
	while (++i < argc)
	{
		argv_cnt = count_argv(argv[i]);
		if (argv_cnt < 1)
			error_exit();
		args_cnt += argv_cnt;
	}
	return (args_cnt);
}
