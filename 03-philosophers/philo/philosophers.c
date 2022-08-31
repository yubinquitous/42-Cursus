/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:44:05 by yubin             #+#    #+#             */
/*   Updated: 2022/08/31 15:49:28 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <unistd.h>

void join_all(int n_philo, t_philo *philo)
{
	int i = -1;

	while (++i < n_philo)
		pthread_join(philo[i].tid, NULL);
}

int run_simulation(t_info info, t_philo *philo, t_end_state *end_state)
{
	int i;
	pthread_t observer_tid;
	t_observer observer;

	i = -1;
	init_observer(&observer, info, philo, end_state);
	while (++i < info.n_philo)
	{
		philo[i].start_time = get_timestamp_now();
		philo[i].last_meal_time = philo[i].start_time;
		if (pthread_create(&(philo[i].tid), NULL, (void *)philo_thread, (void *)&(philo[i])))
			break;
	}
	if (i == info.n_philo &&
		pthread_create(&observer_tid, NULL, (void *)observer_thread, (void *)&observer))
		return (0);
	join_all(i, philo);
	if (i == info.n_philo)
		pthread_join(observer_tid, NULL);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	int result;
	t_info info;
	t_philo *philo;
	t_end_state end_state;

	result = SUCCESS;
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
		result = RUNTIME_FAIL;
	return (result);
}