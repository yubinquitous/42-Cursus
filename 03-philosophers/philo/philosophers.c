/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:44:05 by yubin             #+#    #+#             */
/*   Updated: 2022/08/08 19:30:44 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	if (argc != 5 || argc != 6)
		return (0);
	if (init_info(argv) || init_philo(&info))
		return (0);
}