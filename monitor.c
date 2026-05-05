/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:38:58 by bfernan2          #+#    #+#             */
/*   Updated: 2026/05/05 17:58:34 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->state_mutex);
	if (get_time() - philo->last_meal_time > philo->table->time_to_die)
	{
		pthread_mutex_unlock(&philo->table->state_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->state_mutex);
	return (0);
}

static int	all_ate(t_table *table)
{
	int	i;
	
	if (table->nbr_limit_meals == 1)
		return (0);
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_lock(&table->state_mutex);
		if (table->philos[i].meals_counter < table->nbr_limit_meals)
		{
			pthread_mutex_unlock(&table->state_mutex);
			return (0);
		}
		pthread_mutex_unlock(&table->state_mutex);
		i++;
	}
	return (1);
}

static void	set_end(t_table *table)
{
	pthread_mutex_lock(&table->state_mutex);
	table->end_simulation = true;
	pthread_mutex_unlock(&table->state_mutex);
}
static void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *) arg;
	while (1)
	{
		i = 0;
		while (i < table->philo_nbr)
		{
			if (philo_dead(&table->philos[i]))
			{
				print_state(&table->philos[i], "died");
				set_end(table);
				return (NULL);
			}
			i++;
		}
		if (all_ate(table))
			return (set_end(table), NULL);
	}
	return (NULL);
}