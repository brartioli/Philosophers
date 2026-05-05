/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:37:51 by bfernan2          #+#    #+#             */
/*   Updated: 2026/05/05 17:35:15 by bfernan2         ###   ########.fr       */
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

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(&philo->right_fork->fork);
	print_state(philo, "has taken a fork");
	philo->last_meal_time = get_time();
	philo->meals_counter++;
	print_state(philo, "is eating");
	ft_usleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
}

void	sleep_philo(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep, philo->table);
}

void	think(t_philo *philo)
{
	print_state(philo, "is thinking");	
}