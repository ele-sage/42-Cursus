/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:38:34 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/02 12:19:45 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_philo(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philos)
		return (error(MALLOC, NULL, table));
	i = 0;
	while (i < table->nb_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].eat = 0;
		table->philos[i].last_eat = 0;
		table->philos[i].table = table;
		table->philos[i].forks[0] = i;
		table->philos[i].forks[1] = (i + 1) % table->nb_philo;
		if (pthread_mutex_init(&table->philos[i].mutex, NULL))
			return (error(MUTEX, NULL, table));
		i++;
	}
	return (SUCCESS);
}

static int	init_mutex(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		return (error(MALLOC, NULL, table));
	if (pthread_mutex_init(&table->print, NULL))
		return (error(MUTEX, NULL, table));
	if (pthread_mutex_init(&table->dead, NULL))
		return (error(MUTEX, NULL, table));
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (error(MUTEX, NULL, table));
		i++;
	}
	return (SUCCESS);
}

static int	parse_args(int argc, char **argv, t_table *table)
{
	int	args[5];
	int	i;

	if (argc < 5 || argc > 6)
		return (error(USAGE, NB_ARG, NULL));
	i = 0;
	while (i < argc - 1)
	{
		args[i] = ft_atoi_pos(argv[i + 1]);
		if (args[i] < 0)
			return (error(USAGE, WRONG_ARG, NULL));
		i++;
	}
	if (args[0] > 200 || args[0] < 1)
		return (error(USAGE, NB_PHILO, NULL));
	table->nb_philo = args[0];
	table->t_die = args[1];
	table->t_eat = args[2];
	table->t_sleep = args[3];
	if (argc == 6)
		table->nb_meal = args[4];
	else
		table->nb_meal = -1;
	return (SUCCESS);
}

int	init_table(int argc, char **argv, t_table *table)
{
	if (parse_args(argc, argv, table))
		return (ERROR);
	if (init_mutex(table))
		return (ERROR);
	if (init_philo(table))
		return (ERROR);
	return (SUCCESS);
}
