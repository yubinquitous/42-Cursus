/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:25:35 by yubchoi           #+#    #+#             */
/*   Updated: 2022/04/13 15:25:38 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_param	*param;

	if (argc != 2)
		ft_exit("CHECK ARGC");
	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		ft_exit("PARAM MALLOC ERROR");
	init_and_check(param, argv[1]);
	draw_game(param);
	mlx_hook(param->win, X_EVENT_KEY_PRESS, 0, &key_press, param);
	mlx_hook(param->win, X_EVENT_KEY_EXIT, 0, &key_exit, param);
	mlx_loop(param->mlx);
	exit(0);
}
