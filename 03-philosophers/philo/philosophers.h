/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:44:04 by yubin             #+#    #+#             */
/*   Updated: 2022/08/17 17:28:02 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <pthread.h>

#define CONTEXT_SWITCH_TIME 1024

enum e_status
{
	FAIL,
	SUCCESS,
	INPUT_FAIL,
	MALLOC_FAIL,
	MUTEX_FAIL,
	ONE_PHILO_FAIL,
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
	int max_eat;
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

void acquire_forks(t_philo *philo);
void broadcast_end(t_end_state *end_state);
void destroy_mutex_fork_event(int i, t_philo *philo, t_end_state *end_state);
int ft_atoi(char *str);
int ft_malloc_philo(t_philo **philo, int n_philo);
unsigned long long get_timestamp_now(void);
void increase_n_eat(t_philo *philo);
int init_info(char **argv, t_info *info);
int init_mutex(t_info *info, t_philo *philo, t_end_state *end_state);
int init_mutex_fork_event(pthread_mutex_t *fork, pthread_mutex_t *event);
void init_observer(t_observer *observer, t_info info, t_philo *philo, t_end_state *end_state);
void init_philo(t_info info, t_philo *philo, t_end_state *end_state);
void logger(t_philo *philo, enum e_philo_status);
int main(int argc, char **argv);
void nano_usleep(int usec);
void *observer_thread(t_observer *observer);
char philo_eat(t_philo *philo);
char philo_sleep(t_philo *philo);
char philo_think(t_philo *philo);
void *philo_thread(void *_philo);
int print_err(enum e_status state);
void release_forks(t_philo *philo);
int run_simulation(t_info info, t_philo *philo, t_end_state *end_state);
char simulation_end(t_end_state *end_state);

#endif