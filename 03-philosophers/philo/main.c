/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:44:05 by yubin             #+#    #+#             */
/*   Updated: 2022/09/04 16:45:37 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	t_info info;
	t_philo *philo;
	t_end_state end_state;

	if (argc != 5 && argc != 6)
		return (print_err(INPUT_FAIL));
	if (!init_info(argv, &info))
		return (print_err(INPUT_FAIL));
	if (!ft_malloc_philo((t_philo **)&philo, info.n_philo))
		return (print_err(MALLOC_FAIL));
	init_philo(info, philo, &end_state);
	if (!init_mutex(&info, philo, &end_state))
		return (print_err(MUTEX_FAIL));
	if (!run_simulation(info, philo, &end_state))
		return (print_err(RUNTIME_FAIL));
	return (SUCCESS);
}