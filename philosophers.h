/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:56:04 by bfernan2          #+#    #+#             */
/*   Updated: 2026/04/29 20:51:12 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define PHILO_MAX 200

typedef struct s_table	t_table;

typedef struct	s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct	s_philo
{
	int				id;
	long			meals_counter;
	long			last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
	t_table			*table;
}	t_philo;

typedef struct	s_table
{
	long			philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_limit_meals;
	long			start_simulation;
	bool			end_simulation;
	pthread_mutex_t	write_mutex;//protege saída (printf)
	pthread_mutex_t	state_mutex;//protege dados compartilhados (end_simulation, etc)
	t_fork	*forks;
	t_philo	*philos;
}	t_table;

//utils
void	error_exit(const char *error);
long	ft_atol(char *str);
void	clean(t_table *table);
long	get_time(void);//converte segundos para milisegundos e microsegundos para milisegundo e soma os dois
//parse
int	parse_input(char **argv);
//init
void	data_init(t_table *table, char **argv);
void	init_forks(t_table *table);
void	init_philos(t_table *table);
//dinner
void	dinner_start(t_table *table);
//actions
void	ft_usleep(long ms, t_table *table);
void	print_state(t_philo *philo, char *state);

#endif
