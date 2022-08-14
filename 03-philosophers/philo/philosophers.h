/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:44:04 by yubin             #+#    #+#             */
/*   Updated: 2022/08/14 17:37:57 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <pthread.h>

enum e_status
{
	FAIL,
	SUCCESS,
	INPUT_FAIL,
	MALLOC_FAIL,
	MUTEX_FAIL,
	RUNTIME_FAIL,
};

enum e_philo_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

typedef struct s_end_state
{
	char is_end;
	pthread_mutex_t is_end_lock;
} t_end_state;

typedef struct s_info
{
	int n_philo;
	int ttd;
	int tte;
	int tts;
	int eat_max;
	int has_option;
} t_info;

typedef struct s_philo
{
	int id;
	pthread_t tid;
	int tte;
	int tts;
	int n_eat;
	unsigned long long start_time;
	unsigned long long last_meal_time;
	pthread_mutex_t *lfork;
	pthread_mutex_t *rfork;
	pthread_mutex_t _fork;
	pthread_mutex_t event;
	t_end_state *end_state;
} t_philo;

typedef struct s_observer
{
	t_info info;
	t_philo *philo;
	t_end_state *end_state;
} t_observer;

#endif