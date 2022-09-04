/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:54:36 by yubchoi           #+#    #+#             */
/*   Updated: 2022/09/04 16:43:54 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void join_all(int n_philo, t_philo *philo)
{
    int i = -1;

    while (++i < n_philo)
        pthread_join(philo[i].tid, NULL);
}

void destroy_mutex(int n_philo, t_philo *philo, t_end_state *end_state)
{
    int i;

    i = -1;
    while (++i < n_philo)
    {
        pthread_mutex_destroy(&(philo[i].event));
        pthread_mutex_destroy(&(philo[i]._fork));
    }
    pthread_mutex_destroy(&(end_state->is_end_lock));
}

int run_observer(t_observer *observer)
{
    pthread_t observer_tid;

    if (pthread_create(&observer_tid, NULL, (void *)observer_thread, (void *)observer))
        return (FAIL);
    pthread_join(observer_tid, NULL);
    return (SUCCESS);
}

int run_simulation(t_info info, t_philo *philo, t_end_state *end_state)
{
    int i;
    int result;
    t_observer observer;
    unsigned long long start_time;

    i = -1;
    init_observer(&observer, info, philo, end_state);
    start_time = get_timestamp_now();
    while (++i < info.n_philo)
    {
        philo[i].start_time = start_time;
        philo[i].last_meal_time = get_timestamp_now();
        if (pthread_create(&(philo[i].tid), NULL, (void *)philo_thread, (void *)&(philo[i])))
            break;
    }
    result = i == info.n_philo;
    if (i == info.n_philo)
        result &= run_observer(&observer);
    join_all(i, philo);
    destroy_mutex(i, philo, end_state);
    free(philo);
    return (result);
}