/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:41:54 by yubchoi           #+#    #+#             */
/*   Updated: 2022/09/02 16:21:27 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <stdio.h>

char simulation_end(t_end_state *end_state)
{
	char is_end;

	pthread_mutex_lock(&(end_state->is_end_lock));
	is_end = end_state->is_end;
	pthread_mutex_unlock(&(end_state->is_end_lock));
	return (is_end);
}

int print_err(enum e_status state)
{
	if (state == INPUT_FAIL)
		printf("Usage: /philo n_of_philos ttd tte tts [n_of_must_eat]\n");
	else if (state == MALLOC_FAIL)
		printf("Error: malloc fail\n");
	else if (state == MUTEX_FAIL)
		printf("Error: mutex fail\n");

	return (FAIL);
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

	// print lock
	pthread_mutex_lock(&(philo->end_state->is_end_lock));
	timestamp = get_timestamp_now() - philo->start_time;
	if (!(philo->end_state->is_end))
		printf("%5llu %d %s\n", timestamp, philo->id, status[status_num]);
	// print unlock
	pthread_mutex_unlock(&(philo->end_state->is_end_lock));
}