/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:32:41 by bfernan2          #+#    #+#             */
/*   Updated: 2026/05/05 18:15:15 by bfernan2         ###   ########.fr       */
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

static void	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->write_mutex, NULL) != 0)
	{
		clean(table);
		error_exit("Failed to init write mutex\n");
	}
	if (pthread_mutex_init(&table->state_mutex, NULL) != 0)
	{
		clean(table);
		error_exit("Failed to init state mutex\n");
	}
}

void	dinner_start(t_table *table)
{
	int	i;
	pthread_t	monitor;

	init_forks(table);
	init_philos(table);
	init_mutex(table);
	table->start_simulation = get_time();
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
	if (pthread_create(&monitor, NULL, monitor_routine, table) != 0)
	{
		clean(table);
		error_exit("Failed to create monitor thread/n");
	}
	//join
}