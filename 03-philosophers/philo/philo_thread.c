/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:19:03 by yubin             #+#    #+#             */
/*   Updated: 2022/08/17 17:40:26 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

char simulation_end(t_end_state *end_state)
{
	char is_end;

	pthread_mutex_lock(&(end_state->is_end_lock));
	is_end = end_state->is_end;
	pthread_mutex_unlock(&(end_state->is_end_lock));
	return (is_end);
}

unsigned long long get_timestamp_now(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void logger(t_philo *philo, enum e_philo_status status_num)
{
	unsigned long long timestamp;
	static const char *status[] =
		{
			"has taken fork",
			"is eating",
			"is sleeping",
			"is thinking",
			"died"};

	// pthread_mutex_lock(&(philo->event));
	timestamp = get_timestamp_now() - philo->start_time;
	if (!simulation_end(philo->end_state))
		printf("%5llu %d %s\n", timestamp, philo->id, status[status_num]);
	// pthread_mutex_unlock(&(philo->event));
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

void nano_usleep(int millisec)
{
	unsigned long long start;

	start = get_timestamp_now();
	while (1)
	{
		if (get_timestamp_now() - start >= millisec)
			break;
		usleep(CONTEXT_SWITCH_TIME);
	}
}

void update_philo_info(t_philo *philo)
{
	pthread_mutex_lock(&(philo->event));
	++philo->n_eat;
	philo->last_meal_time = get_timestamp_now();
	pthread_mutex_unlock(&(philo->event));
}

char philo_eat(t_philo *philo)
{
	acquire_forks(philo);
	logger(philo, EAT);
	nano_usleep(philo->tte);
	release_forks(philo);
	update_philo_info(philo);
	if (simulation_end(philo->end_state))
		return (FAIL);
	return (SUCCESS);
}

char philo_sleep(t_philo *philo)
{
	logger(philo, SLEEP);
	nano_usleep(philo->tts);
	if (simulation_end(philo->end_state))
		return (FAIL);
	return (SUCCESS);
}

char philo_think(t_philo *philo)
{
	logger(philo, THINK);
	if (simulation_end(philo->end_state))
		return (FAIL);
	return (SUCCESS);
}

void *philo_thread(void *_philo)
{
	t_philo *philo;

	philo = (t_philo *)_philo;
	if (philo->id % 2)
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