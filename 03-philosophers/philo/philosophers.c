/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:44:05 by yubin             #+#    #+#             */
/*   Updated: 2022/08/18 14:43:43 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	return (n);
}

char init_info(char **argv, t_info *info)
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
	if (info->n_philo < 1 || !info->ttd || !info->tte || !info->tts || (info->has_option && !info->max_eat))
		return (FAIL);
	return (SUCCESS);
}

char ft_malloc_philo(t_philo **philo, int n_philo)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * n_philo);
	return (*philo != NULL);
}

void init_philo(t_info info, t_philo *philo, t_end_state *end_state)
{
	int i = -1;

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

int init_mutex(t_info *info, t_philo *philo, t_end_state *end_state)
{
	int i = -1;

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

void init_observer(t_observer *observer, t_info info, t_philo *philo, t_end_state *end_state)
{
	observer->info = info;
	observer->philo = philo;
	observer->end_state = end_state;
}

void broadcast_end(t_end_state *end_state)
{
	pthread_mutex_lock(&(end_state->is_end_lock));
	end_state->is_end = 1;
	pthread_mutex_unlock(&(end_state->is_end_lock));
}

char philo_starving(t_philo *philo, int ttd)
{
	if (get_timestamp_now() - philo->last_meal_time > ttd)
	{
		logger(philo, DIE);
		return (1);
	}
	return (0);
}

char anyone_starving_everyone_full(t_info info, t_philo *philo)
{
	int i;
	char full;

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

void *observer_thread(t_observer *observer)
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

void join_all(int n_philo, t_philo *philo)
{
	int i = -1;

	while (++i < n_philo)
		pthread_join(philo[i].tid, NULL);
}

int run_simulation(t_info info, t_philo *philo, t_end_state *end_state)
{
	int i;
	pthread_t observer_tid;
	t_observer observer;

	i = -1;
	init_observer(&observer, info, philo, end_state);
	while (++i < info.n_philo)
	{
		philo[i].start_time = get_timestamp_now();
		philo[i].last_meal_time = philo[i].start_time;
		if (pthread_create(&(philo[i].tid), NULL, (void *)philo_thread, (void *)&(philo[i])))
			break;
	}
	if (i == info.n_philo &&
		pthread_create(&observer_tid, NULL, (void *)observer_thread, (void *)&observer))
		return (0);
	join_all(i, philo);
	if (i == info.n_philo)
		pthread_join(observer_tid, NULL);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	int result;
	t_info info;
	t_philo *philo;
	t_end_state end_state;

	result = SUCCESS;
	if (argc != 5 && argc != 6)
		return (print_err(INPUT_FAIL));
	if (!init_info(argv, &info))
		return (print_err(INPUT_FAIL));
	if (!ft_malloc_philo((t_philo **)&philo, info.n_philo))
		return (print_err(MALLOC_FAIL));
	init_philo(info, philo, &end_state);
	if (!init_mutex(&info, philo, &end_state))
		return (print_err(MUTEX_FAIL));
	if (!run_simulation(info, philo, &end_state))
		result = RUNTIME_FAIL;
	return (result);
}