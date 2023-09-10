/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:29:47 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/09 15:54:10 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define USAGE "Usage: ./philo [nb_philo] [time_to_die] [time_to_eat] \
[time_to_sleep] [nb_meal (optional)]\n"
# define NB_PHILO "Error: number of philosophers must be between 1 and 200\n"
# define NB_ARG "Error: wrong number of arguments\n"
# define WRONG_ARG "Error: wrong argument\n"
# define MALLOC "Error: malloc failed\n"
# define THREAD "Error: thread creation failed\n"
# define MUTEX "Error: mutex creation failed\n"

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEAD "\e[0;31mdied\e[0m\n"

# define SUCCESS 0
# define ERROR 1

typedef struct s_philo	t_philo;

typedef struct s_table
{
	unsigned int		nb_philo;
	int					nb_meal;
	int					sim_state;
	uint64_t			t_die;
	uint64_t			t_eat;
	uint64_t			t_sleep;
	uint64_t			start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		dead;
	t_philo				*philos;
	pthread_t			monitor;
}						t_table;

struct					s_philo
{
	unsigned int		id;
	unsigned int		eat;
	int					forks[2];
	int					state;
	uint64_t			last_eat;
	t_table				*table;
	pthread_t			thread;
};

int			init_table(int argc, char **argv, t_table *table);
int			create_threads(t_table *table);
int			error(const char *err1, const char *err2, t_table *table);
void		free_table(t_table *table);
uint64_t	get_time(void);
void		ft_usleep(uint64_t time, t_table *table);
void		print_action(t_philo *philo, const char *action);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);

#endif