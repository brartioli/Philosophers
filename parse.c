/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:33:02 by bfernan2          #+#    #+#             */
/*   Updated: 2026/04/25 15:35:44 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_number_arg(char *str)
{
	int i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1)
}

int	parse_input(t_table *table, char **argv)
{
	if (is_number_arg(argv[1]) || ft_atol(argv[1]) <= 0)
		return (write(2, "Error: Invalid number of philosophers\n", 38), 1);
	if (is_number_arg(argv[2]) || ft_atol(argv[2]) <= 0)
		return (write(2, "Error: Invalid time to die\n", 27), 1);
	if (is_number_arg(argv[3]) || ft_atol(argv[3]) <= 0)
		return (write(2, "Error: Invalid time to eat\n", 27), 1);
	if (is_number_arg(argv[4]) || ft_atol(argv[4]) <= 0)
		return (write(2, "Error: Invalid time to sleep\n", 29), 1);
	if (argv[5] && (is_number_arg(argv[5]) || ft_atol(argv[5])  <= 0))
		return (write(2, "Error: Invalid number of meals\n", 31), 1);
	return (0);
}
