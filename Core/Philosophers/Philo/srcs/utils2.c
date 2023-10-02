/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:25:57 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/02 14:42:11 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_dead(t_table *table)
{
	pthread_mutex_lock(&table->dead);
	if (table->sim_state == 0)
	{
		pthread_mutex_unlock(&table->dead);
		return (1);
	}
	pthread_mutex_unlock(&table->dead);
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (long long)1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long long time, t_table *table)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time && !is_dead(table))
		usleep(100);
}

void	print_action(t_philo *philo, const char *action)
{
	long long	time;

	pthread_mutex_lock(&philo->table->print);
	if (is_dead(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	time = get_time() - philo->table->start_time;
	printf("%lld %d %s", time, philo->id, action);
	pthread_mutex_unlock(&philo->table->print);
}

int	all_satisfied(t_table *table, int satisfied)
{
	if (satisfied == table->nb_philo)
	{
		pthread_mutex_lock(&table->print);
		pthread_mutex_lock(&table->dead);
		table->sim_state = 0;
		printf("%lld %s", get_time() - table->start_time, SATISFIED);
		pthread_mutex_unlock(&table->dead);
		pthread_mutex_unlock(&table->print);
		return (1);
	}
	return (0);
}
