/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:46:46 by bfernan2          #+#    #+#             */
/*   Updated: 2026/04/13 20:35:21 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (5 == argc || 6 == argc)
	{
		//correct input
		//parse_input(&table, argv)
		//data_init(&table)
		//dinner_start(&table)
		//clean(&table)
	}
	else
		error_exit("Wrong iput:\n");
	return (0);
}