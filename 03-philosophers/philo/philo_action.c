/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:44:55 by yubchoi           #+#    #+#             */
/*   Updated: 2022/09/04 16:43:54 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

char philo_eat(t_philo *philo)
{
	acquire_forks(philo);
	logger(philo, EAT);
	nano_usleep(philo->tte);
	release_forks(philo);
	update_philo_info(philo);
	return (!simulation_end(philo->end_state));
}

char philo_sleep(t_philo *philo)
{
	logger(philo, SLEEP);
	nano_usleep(philo->tts);
	return (!simulation_end(philo->end_state));
}

char philo_think(t_philo *philo)
{
	logger(philo, THINK);
	usleep(CONTEXT_SWITCH_TIME);
	return (!simulation_end(philo->end_state));
}