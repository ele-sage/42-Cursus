/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:07:03 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/09 15:54:06 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->forks[0]]);
	print_action(philo, FORK);
	pthread_mutex_lock(&philo->table->forks[philo->forks[1]]);
	print_action(philo, FORK);
	print_action(philo, EAT);
	philo->last_eat = get_time();
	ft_usleep(philo->table->t_eat, philo->table);
	pthread_mutex_unlock(&philo->table->forks[philo->forks[0]]);
	pthread_mutex_unlock(&philo->table->forks[philo->forks[1]]);
	philo->eat++;
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->nb_philo == 1)
		return (NULL);
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->t_eat, philo->table);
	while (philo->table->sim_state)
	{
		eat(philo);
		print_action(philo, SLEEP);
		ft_usleep(philo->table->t_sleep, philo->table);
		print_action(philo, THINK);
	}
	return (NULL);
}

static int	monitoring_loop(t_table *table, int i, int satisfied)
{
	while (i < table->nb_philo)
	{
		if (table->philos[i].eat >= table->nb_meal)
			satisfied++;
		if (get_time() - table->philos[i].last_eat > table->t_die)
		{
			pthread_mutex_lock(&table->dead);
			print_action(&table->philos[i], DEAD);
			table->sim_state = 0;
			pthread_mutex_unlock(&table->dead);
			return (1);
		}
		i++;
	}
	if (satisfied == table->nb_philo)
		table->sim_state = 0;
	return (0);
}

static void	*monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	if (table->nb_philo == 1)
	{
		ft_usleep(table->t_die, table);
		print_action(&table->philos[0], DEAD);
		table->sim_state = 0;
		return (NULL);
	}
	while (table->sim_state)
		if (monitoring_loop(table, 0, 0))
			return (NULL);
	printf("\e[0;32mAll philosophers are satisfied\e[0m\n");
	return (NULL);
}

int	create_threads(t_table *table)
{
	int	i;

	table->start_time = get_time();
	table->sim_state = 1;
	i = 0;
	while (i < table->nb_philo)
	{
		table->philos[i].last_eat = get_time();
		if (pthread_create(&table->philos[i].thread, NULL, &routine,
				&table->philos[i]))
			return (error(THREAD, NULL, table));
		i++;
	}
	if (pthread_create(&table->monitor, NULL, &monitor, table))
		return (error(THREAD, NULL, table));
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (error(THREAD, NULL, table));
		i++;
	}
	if (pthread_join(table->monitor, NULL))
		return (error(THREAD, NULL, table));
	return (SUCCESS);
}
