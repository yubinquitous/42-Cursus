/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:25:29 by yubchoi           #+#    #+#             */
/*   Updated: 2022/04/13 15:25:32 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_func(t_param *param, int changing_row, int changing_col)
{
	int		target_row;
	int		target_col;
	int		n_row;
	int		n_col;
	char	**map;

	target_row = param->game->cur_row + changing_row;
	target_col = param->game->cur_col + changing_col;
	n_row = param->game->n_row;
	n_col = param->game->n_col;
	map = param->game->map;
	if (0 < target_row && target_row < n_row - 1 && 0 < target_col
		&& target_col < n_col - 1 && map[target_row][target_col] != '1')
	{
		if (map[target_row][target_col] == 'E')
			move_to_exit(param, target_row, target_col);
		else
			move_player(param, target_row, target_col);
		printf("MOVEMENT : %d\n", ++(param->game->n_move));
	}
}

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		key_exit(param);
	else if (keycode == KEY_W)
		key_func(param, -1, 0);
	else if (keycode == KEY_S)
		key_func(param, 1, 0);
	else if (keycode == KEY_A)
		key_func(param, 0, -1);
	else if (keycode == KEY_D)
		key_func(param, 0, 1);
	return (0);
}
