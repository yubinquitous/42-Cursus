/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:19:03 by yubin             #+#    #+#             */
/*   Updated: 2022/09/04 17:03:07 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	*philo_one_thread(t_philo *philo)
{
	pthread_mutex_lock(&(philo->_fork));
	logger(philo, FORK);
	while (simulation_end(philo->end_state))
		usleep(CONTEXT_SWITCH_TIME);
	pthread_mutex_unlock(&(philo->_fork));
	return (NULL);
}

void	*philo_thread(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	if (philo->n_philo == 1)
		return (philo_one_thread(philo));
	if (philo->id % 2)
		usleep(CONTEXT_SWITCH_TIME);
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
