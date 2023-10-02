/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:07:03 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/02 14:42:08 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->table->forks[philo->forks[0]]);
	print_action(philo, FORK);
	pthread_mutex_lock(&philo->table->forks[philo->forks[1]]);
	print_action(philo, FORK);
	pthread_mutex_lock(&philo->mutex);
	time = get_time();
	if (time - philo->last_eat < philo->table->t_die)
	{
		print_action(philo, EAT);
		philo->last_eat = time;
		philo->eat++;
	}
	pthread_mutex_unlock(&philo->mutex);
	ft_usleep(philo->table->t_eat, philo->table);
	pthread_mutex_unlock(&philo->table->forks[philo->forks[0]]);
	pthread_mutex_unlock(&philo->table->forks[philo->forks[1]]);
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->nb_philo == 1)
		return (NULL);
	if (philo->id % 2 == 0)
	{
		print_action(philo, THINK);
		ft_usleep(philo->table->t_eat, philo->table);
	}
	while (!is_dead(philo->table))
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
		pthread_mutex_lock(&table->philos[i].mutex);
		if (table->philos[i].eat >= table->nb_meal)
			satisfied++;
		if (get_time() - table->philos[i].last_eat >= table->t_die)
		{
			pthread_mutex_lock(&table->print);
			pthread_mutex_lock(&table->dead);
			table->sim_state = 0;
			printf("%lld %d %s", get_time() - table->start_time,
				table->philos[i].id, DEAD);
			pthread_mutex_unlock(&table->dead);
			pthread_mutex_unlock(&table->print);
			pthread_mutex_unlock(&table->philos[i].mutex);
			return (1);
		}
		pthread_mutex_unlock(&table->philos[i].mutex);
		i++;
	}
	return (all_satisfied(table, satisfied));
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
	while (monitoring_loop(table, 0, 0) == 0)
		;
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
		table->philos[i].last_eat = table->start_time;
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
