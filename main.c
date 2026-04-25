/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:46:46 by bfernan2          #+#    #+#             */
/*   Updated: 2026/04/25 14:42:40 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;
	if (argc != 5 && argc != 6)
		return(printf("Error: Wrong argument count\n"), 1);
	if(parse_input(&table, argv) != 0)
		return (1);
	//inicia
	//inicia_jantar
	//clean
	return (0);
}