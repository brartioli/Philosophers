/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:32:41 by bfernan2          #+#    #+#             */
/*   Updated: 2026/04/29 20:35:06 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eat(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	init_forks(table);
	init_philos(table);
	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL,
				philo_routine, &table->philos[i]) != 0)
		{
			clean(table);
			error_exit("Failed to create thread\n");
		}
		i++;
	}
	//monitor
	//join
}