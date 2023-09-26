/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:14:18 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/26 12:26:36 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	if (table->forks)
	{
		while (i < table->nb_philo)
			pthread_mutex_destroy(&table->forks[i++]);
		free(table->forks);
		pthread_mutex_destroy(&table->print);
		pthread_mutex_destroy(&table->dead);
	}
	if (table->philos)
		free(table->philos);
	free(table);
}

int	error(const char *err1, const char *err2, t_table *table)
{
	if (err1)
		write(2, err1, ft_strlen(err1));
	if (err2)
		write(2, err2, ft_strlen(err2));
	if (table)
		free_table(table);
	return (ERROR);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (long long)1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

// if one of the philosophers is dead
// do not print the last action
void	print_action(t_philo *philo, const char *action)
{
	long long	time;

	pthread_mutex_lock(&philo->table->print);
	if (philo->table->sim_state)
	{
		time = get_time() - philo->table->start_time;
		printf("%lld %d %s", time, philo->id, action);
	}
	pthread_mutex_unlock(&philo->table->print);
}
