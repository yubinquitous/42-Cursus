/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:44:05 by yubin             #+#    #+#             */
/*   Updated: 2022/08/14 17:38:05 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	if (!str[i])
		return (FAIL);
	return (n);
}

int init_info(char **argv, t_info *info)
{
	if (argc != 5 || argc != 6)
		return (FAIL);
	info->n_philo = argv[1];
	info->ttd = argv[2];
	info->tte = argv[3];
	info->tts = argv[4];
	if (!argv[5])
		info->has_option = 0;
	else
	{
		info->has_option = 1;
		info->eat_max = argv[5];
	}
	if (info->n_philo < 1 || !info->ttd || !info->tte || !info->tts || (info->has_option && !info->n_eat))
		return (FAIL);
}

int ft_malloc_philo(t_philo **philo)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * info.n_philo);
	return (*philo != NULL);
}

void init_philo(t_info info, t_philo *philo, t_end_state *end_state)
{
	int i = -1;

	end_state->is_end = 0;
	while (++i < info.n_philo)
	{
		philo[i].id = i + 1;
		philo[i].tte = info.tte;
		philo[i].tts = info.tts;
		philo[i].n_eat = 0;
		philo[i].lfork = &(philo[i]._fork);
		philo[i].rfork = &(philo[(i + 1) % info.n_philo]._fork);
		philo[i].end_state = end_state;
	}
}

// void free_philo(t_philo **philo)
// {
// 	free(*philo);
// 	*philo = NULL;
// }

int print_err(enum e_state state, t_philo **philo)
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
	if (pthread_mutex_init(*fork, NULL) == -1)
		return (FAIL);
	if (pthread_mutex_init(*event, NULL) == -1)
	{
		pthread_mutex_destroy(*fork);
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
	while (++i < info->n_philo)
	{
		if (!init_mutex_fork_event(&(philo[i]._fork, &(philo[i].event))))
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
		philo[i].last_meal_time = get_timestamp_now();
		if (pthread_create(&(philo[i].tid), NULL, philo_thread, (void *)&(philo[i])))
			return (abort_simulation(i, philo, end_state));
	}
	if (pthread_create(&observer_tid, NULL, (void *)observer_thread, (void *)&observer))
		return (abort_simulation(i, philo, end_state));
}

int main(int argc, char **argv)
{
	int result;
	t_info info;
	t_philo *philo;
	t_end_state end_state;

	result = SUCCESS;
	if (!init_info(argc, argv, &info))
		return (print_err(INPUT_FAIL));
	if (!ft_malloc_philo(&philo))
		return (print_err(MALLOC_FAIL));
	init_philo(&argc, philo, &end_state);
	if (!init_mutex(&info, philo, &end_state))
		return (print_err(MUTEX_FAIL));
	if (!run_simulation(info, philo, &end_state))
		result = RUNTIME_FAIL;
}