/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:14:18 by ele-sage          #+#    #+#             */
/*   Updated: 2023/10/02 14:29:53 by ele-sage         ###   ########.fr       */
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
		{
			pthread_mutex_destroy(&table->philos[i].mutex);
			pthread_mutex_destroy(&table->forks[i++]);
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->dead);
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

size_t	ft_strlen(const char *str)
{
	size_t	a;

	if (!str)
		return (0);
	a = 0;
	while (str[a])
		a++;
	return (a);
}

int	ft_atoi_pos(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!str)
		return (-1);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '0')
		return (-1);
	if (ft_strlen(str + i) > 10)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (str[i])
		return (-1);
	return (nb);
}
