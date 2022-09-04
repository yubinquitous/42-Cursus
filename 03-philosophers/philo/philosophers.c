/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:44:05 by yubin             #+#    #+#             */
/*   Updated: 2022/09/04 15:53:29 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void join_all(int n_philo, t_philo *philo)
{
	int i = -1;

	while (++i < n_philo)
		pthread_join(philo[i].tid, NULL);
}

void destroy_mutex(int n_philo, t_philo *philo, t_end_state *end_state)
{
	int i;

	i = -1;
	while (++i < n_philo)
	{
		pthread_mutex_destroy(&(philo[i].event));
		pthread_mutex_destroy(&(philo[i]._fork));
	}
	pthread_mutex_destroy(&(end_state->is_end_lock));
}

int run_observer(t_observer *observer)
{
	pthread_t observer_tid;

	if (pthread_create(&observer_tid, NULL, (void *)observer_thread, (void *)observer))
		return (FAIL);
	pthread_join(observer_tid, NULL);
	return (SUCCESS);
}

int run_simulation(t_info info, t_philo *philo, t_end_state *end_state)
{
	int i;
	int result;
	t_observer observer;
	unsigned long long start_time;

	i = -1;
	init_observer(&observer, info, philo, end_state);
	start_time = get_timestamp_now();
	while (++i < info.n_philo)
	{
		philo[i].start_time = start_time;
		philo[i].last_meal_time = get_timestamp_now();
		if (pthread_create(&(philo[i].tid), NULL, (void *)philo_thread, (void *)&(philo[i])))
			break;
	}
	result = i == info.n_philo;
	if (i == info.n_philo)
		result &= run_observer(&observer);
	join_all(i, philo);
	destroy_mutex(i, philo, end_state);
	free(philo);
	return (result);
}

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