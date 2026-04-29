/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:39:49 by bfernan2          #+#    #+#             */
/*   Updated: 2026/04/29 20:08:59 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	data_init(t_table *table, char **argv)
{
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->nbr_limit_meals = -1;
	if (argv[5])
		table->nbr_limit_meals = ft_atol(argv[5]);
	table->end_simulation = false;
	table->start_simulation = 0;
	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	if (!table->forks)
		error_exit("Failed to allocate forks\n");
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!table->philos)
	{
		free(table->forks);
		error_exit("Failed to allocate philosophers\n");
	}
}

void	init_forks(t_table *table)
{
	int	i;
	
	i = 0;
	while(i < table->philo_nbr)
	{
		if (pthread_mutex_init(&table->forks[i].fork, NULL) != 0)
		{
			clean(table);
			error_exit("Failed to init fork mutex");
		}
		table->forks[i].fork_id = i;
		i++;
	}
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_counter = 0;
		table->philos[i].last_meal_time = 0;
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->philo_nbr];
		i++;
	}
}
