/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:30:03 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/09 15:56:04 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table || init_table(argc, argv, table))
	{
		if (table)
			free(table);
		return (ERROR);
	}
	if (create_threads(table))
		return (ERROR);
	free_table(table);
	return (SUCCESS);
}
