/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:47:39 by yubchoi           #+#    #+#             */
/*   Updated: 2022/09/04 17:01:50 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	init_info(char **argv, t_info *info)
{
	info->n_philo = ft_atoi(argv[1]);
	info->ttd = ft_atoi(argv[2]);
	info->tte = ft_atoi(argv[3]);
	info->tts = ft_atoi(argv[4]);
	if (!argv[5])
		info->has_option = 0;
	else
	{
		info->has_option = 1;
		info->max_eat = ft_atoi(argv[5]);
	}
	if (info->n_philo < 1 || !info->ttd || !info->tte || !info->tts
		|| (info->has_option && !info->max_eat))
		return (FAIL);
	return (SUCCESS);
}

void	init_philo(t_info info, t_philo *philo, t_end_state *end_state)
{
	int	i;

	i = -1;
	while (++i < info.n_philo)
	{
		philo[i].id = i + 1;
		philo[i].tte = info.tte;
		philo[i].tts = info.tts;
		philo[i].n_eat = 0;
		philo[i].n_philo = info.n_philo;
		philo[i].lfork = &(philo[i]._fork);
		philo[i].rfork = &(philo[(i + 1) % info.n_philo]._fork);
		philo[i].end_state = end_state;
	}
}

int	init_mutex(t_info *info, t_philo *philo, t_end_state *end_state)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&(end_state->is_end_lock), NULL) == -1)
		return (FAIL);
	end_state->is_end = 0;
	while (++i < info->n_philo)
	{
		if (!init_mutex_fork_event(&(philo[i]._fork), &(philo[i].event)))
		{
			destroy_mutex_fork_event(i, philo, end_state);
			return (FAIL);
		}
	}
	return (SUCCESS);
}

void	init_observer(
	t_observer *observer,
	t_info info,
	t_philo *philo,
	t_end_state *end_state)
{
	observer->info = info;
	observer->philo = philo;
	observer->end_state = end_state;
}
