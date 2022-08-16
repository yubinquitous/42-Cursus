/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:19:03 by yubin             #+#    #+#             */
/*   Updated: 2022/08/16 21:55:24 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char simulation_end(t_end_state *end_state)
{
	pthread_mutex_lock(end_state->is_end_lock);
	if (end_state->is_end)
	{
		pthread_mutex_unlock(end_state->is_end_lock);
		return (1);
	}
	pthread_mutex_unlock(end_state->is_end_lock);
	return (0);
}

unsigned long long get_timestamp_now(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void logger(t_philo *philo, e_num e_philo_status)
{
	unsigned long long timestamp;
	static const char *status[] =
		{
			"has taken fork",
			"is eating",
			"is sleeping",
			"is thinking",
			"died"};

	pthread_mutex_lock(philo->end_state->event);
	timestamp = get_timestamp_now() - philo->start_time;
	if (simulation_end(philo->end_state))
		printf("%llu %d %s\n", timestamp, philo->id, status[e_philo_status]);
	pthread_mutex_unlock(philo->end_state->event);
}

void acquire_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	logger(philo, FORK);
	pthread_mutex_lock(philo->rfork);
	logger(philo, FORK);
}

void release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void nano_usleep(int usec)
{
	unsigned long long start;

	start = get_timestamp_now();
	while (1)
	{
		usleep(usec);
		if (get_timestamp_now() - start >= usec)
			break;
	}
}

void increase_n_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->end_state->event);
	++philo->n_eat;
	pthread_mutex_unlock(philo->end_state->event);
}

char philo_eat(t_philo *philo)
{
	acquire_forks(philo);
	pthread_mutex_lock(philo->end_state->event);
	philo->last_meal_time = get_timestamp_now();
	pthread_mutex_unlock(philo->end_state->event);
	logger(*philo, eat);
	nano_usleep(philo->tte);
	release_forks(philo);
	increase_n_eat(philo);
	if (simulation_end(philo->end_state))
		return (FAIL);
	return (SUCCESS);
}

char philo_sleep(t_philo *philo)
{
	logger(*philo, sleep);
	nano_usleep(philo->tts);
	if (simulation_end(philo->end_state))
		return (FAIL);
	return (SUCCESS);
}

char philo_think(t_philo *philo)
{
	logger(*philo, think);
	if (simulation_end(philo->end_state))
		return (FAIL);
	return (SUCCESS);
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
		if (!philo_sleep(philo))
			return (NULL);
		if (!philo_think(philo))
			return (NULL);
	}
}