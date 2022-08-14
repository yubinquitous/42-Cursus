/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:19:03 by yubin             #+#    #+#             */
/*   Updated: 2022/08/14 17:57:16 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

unsigned long long get_timestamp_now(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void logger(t_philo philo, e_num e_philo_status)
{
	unsigned long long timestamp;
	static const char *status[] =
		{
			"has taken fork",
			"is eating",
			"is sleeping",
			"is thinking",
			"died"};

	pthread_mutex_lock(philo.event);
	timestamp = get_timestamp_now() - philo.start_time;
	if (!philo.is_end)
		printf("%llu %d %s\n", timestamp, philo.id, status[e_philo_status]);
	pthread_mutex_unlock(philo.event);
}

void take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	logger(*philo, FORK);
	pthread_mutex_lock(philo->rfork);
	logger(*philo, FORK);
}

int philo_eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(philo->event);
	philo->last_meal_time = get_timestamp_now();
	pthread_mutex_unlock(philo->event);
	logger(*philo, eat);
	// usleep tte
	return (FAIL);
}

void *philo_thread(void *_philo)
{
	t_philo philo;

	philo = (t_philo *)_philo;
	if (philo.id % 2)
		usleep(1000);
	while (1)
	{
		if (!philo_eat(philo))
			return (NULL);
		// if (!philo_sleep(philo))
		// 	return (NULL);
		// if (!philo_think(philo))
		// 	return (NULL);
	}
}