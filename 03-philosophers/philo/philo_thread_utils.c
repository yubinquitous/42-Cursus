/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:41:04 by yubchoi           #+#    #+#             */
/*   Updated: 2022/09/04 17:02:52 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	acquire_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->lfork);
		logger(philo, FORK);
		pthread_mutex_lock(philo->rfork);
		logger(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->rfork);
		logger(philo, FORK);
		pthread_mutex_lock(philo->lfork);
		logger(philo, FORK);
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	nano_usleep(int millisec)
{
	unsigned long long	start;

	start = get_timestamp_now();
	while (1)
	{
		if (get_timestamp_now() - start >= (unsigned long long)millisec)
			break ;
		usleep(CONTEXT_SWITCH_TIME);
	}
}

void	update_philo_info(t_philo *philo)
{
	pthread_mutex_lock(&(philo->event));
	++philo->n_eat;
	philo->last_meal_time = get_timestamp_now();
	pthread_mutex_unlock(&(philo->event));
}
