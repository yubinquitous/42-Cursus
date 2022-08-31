/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:48:33 by yubchoi           #+#    #+#             */
/*   Updated: 2022/08/31 17:23:23 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

int ft_atoi(char *str)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		++i;
	if (str[i] == '-')
		return (FAIL);
	if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		++i;
	}
	if (str[i])
		return (FAIL);
	return (n);
}

char ft_malloc_philo(t_philo **philo, int n_philo)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * n_philo);
	return (*philo != NULL);
}

int init_mutex_fork_event(pthread_mutex_t *fork, pthread_mutex_t *event)
{
	if (pthread_mutex_init(fork, NULL) == -1)
		return (FAIL);
	if (pthread_mutex_init(event, NULL) == -1)
	{
		pthread_mutex_destroy(fork);
		return (FAIL);
	}
	return (SUCCESS);
}

void destroy_mutex_fork_event(int i, t_philo *philo, t_end_state *end_state)
{
	while (i--)
	{
		pthread_mutex_destroy(&(philo[i]._fork));
		pthread_mutex_destroy(&(philo[i].event));
	}
	pthread_mutex_destroy(&(end_state->is_end_lock));
}