/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:44:04 by yubin             #+#    #+#             */
/*   Updated: 2022/08/08 19:14:34 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

typedef struct s_info
{
	int n_philo;
	int ttd;
	int tte;
	int tts;
	int n_eat;
} t_info;

typedef struct s_philo
{
	t_info info;
	int *status;
	int *eating;
	int *thinking;
	int *eating_count;
	int *eating_count_max;
	int *sleeping;
} t_philo;

#endif