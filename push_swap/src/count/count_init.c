/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:37:30 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/15 12:47:49 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	count_argv(char *str)
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
			if (!ft_isdigit(temp[i][j]))
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
	int	cnt;

	i = 0;
	cnt = 0;
	while (++i < argc)
		cnt += count_argv(argv[i]);
	return (cnt);
}
