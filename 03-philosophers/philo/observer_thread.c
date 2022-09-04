/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:46:21 by yubchoi           #+#    #+#             */
/*   Updated: 2022/09/04 17:02:26 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	broadcast_end(t_end_state *end_state)
{
	pthread_mutex_lock(&(end_state->is_end_lock));
	end_state->is_end = 1;
	pthread_mutex_unlock(&(end_state->is_end_lock));
}

char	philo_starving(t_philo *philo, int ttd)
{
	if (get_timestamp_now() - philo->last_meal_time > (unsigned long long)ttd)
	{
		logger(philo, DIE);
		return (1);
	}
	return (0);
}

char	anyone_starving_everyone_full(t_info info, t_philo *philo)
{
	int		i;
	char	full;

	i = -1;
	full = info.has_option;
	while (++i < info.n_philo)
	{
		pthread_mutex_lock(&(philo[i].event));
		if (philo_starving(&(philo[i]), info.ttd))
		{
			pthread_mutex_unlock(&(philo[i].event));
			return (1);
		}
		if (info.has_option && philo[i].n_eat < info.max_eat)
			full = 0;
		pthread_mutex_unlock(&(philo[i].event));
	}
	return (full);
}

void	*observer_thread(t_observer *observer)
{
	while (1)
	{
		if (simulation_end(observer->end_state))
			return (NULL);
		if (anyone_starving_everyone_full(observer->info, observer->philo))
		{
			broadcast_end(observer->end_state);
			return (NULL);
		}
		usleep(CONTEXT_SWITCH_TIME);
	}
}
