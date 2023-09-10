/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:14:18 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/09 15:54:29 by ele-sage         ###   ########.fr       */
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

uint64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000));
}

void	ft_usleep(uint64_t time, t_table *table)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time && table->sim_state)
		usleep(100);
}

void	print_action(t_philo *philo, const char *action)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->table->print);
	time = get_time() - philo->table->start_time;
	printf("%llums\t#%d\t%s", time, philo->id, action);
	pthread_mutex_unlock(&philo->table->print);
}
