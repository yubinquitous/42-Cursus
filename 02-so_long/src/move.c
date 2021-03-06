/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:25:41 by yubchoi           #+#    #+#             */
/*   Updated: 2022/04/13 15:25:44 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_to_exit(t_param *param, int target_row, int target_col)
{
	t_game	*game;

	game = param->game;
	if (game->collection == 0)
		exit_game(param);
	ft_draw_image(param, "./asset/empty.xpm", game->cur_row, game->cur_col);
	game->cur_row = target_row;
	game->cur_col = target_col;
	ft_draw_image(param, "./asset/exit.xpm", game->cur_row, game->cur_col);
	ft_draw_image(param, "./asset/kirby.xpm", game->cur_row, game->cur_col);
}

void	move_player(t_param *param, int target_row, int target_col)
{
	t_game	*game;
	char	**map;

	game = param->game;
	map = param->game->map;
	if (map[game->cur_row][game->cur_col] == 'E')
		ft_draw_image(param, "./asset/exit.xpm", game->cur_row, game->cur_col);
	else
		ft_draw_image(param, "./asset/empty.xpm", game->cur_row, game->cur_col);
	game->cur_row = target_row;
	game->cur_col = target_col;
	if (map[game->cur_row][game->cur_col] == 'C')
	{
		--(game->collection);
		map[game->cur_row][game->cur_col] = '0';
		ft_draw_image(param, "./asset/empty.xpm", game->cur_row, game->cur_col);
	}
	ft_draw_image(param, "./asset/kirby.xpm", game->cur_row, game->cur_col);
}
