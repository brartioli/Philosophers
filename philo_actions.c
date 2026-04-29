/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:37:51 by bfernan2          #+#    #+#             */
/*   Updated: 2026/04/29 20:44:47 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->table->write_mutex);
	printf("%ld %d %s\n", get_time() - philo->table->start_simulation,
		philo->id, state);
	pthread_mutex_unlock(&philo->table->write_mutex);
}

void	ft_usleep(long ms, t_table *table)
{
	long	start;

	start = get_time();
	while (get_time() - start < ms)
	{
		if (table->end_simulation)
			break ;
		usleep(500);
	}
}