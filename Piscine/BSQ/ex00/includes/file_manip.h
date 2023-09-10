/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manip.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:16:38 by ele-sage          #+#    #+#             */
/*   Updated: 2022/12/14 22:29:59 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANIP_H
# define FILE_MANIP_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000000
# endif

# define BUFFER_INIT 4096
# define BUFFER_STDIN 280000

typedef struct s_data
{
	char			*map;
	char			empty;
	char			obstacle;
	char			filler;
	unsigned int	nb_lines;
	unsigned int	len_lines;
	unsigned long	n;
	int				fd;
}					t_data;

typedef struct s_coin
{
	int				corner[2];
	int				len;
}					t_coin;

void				init_data(t_data *data);
int					read_stdin(t_data *data);
int					read_file(t_data *data, char *file);
int					map_arg(t_data *data);
void				print_map(t_data data);
void				print_map_solution(t_data data, t_coin coin);
char				*ft_strjoin(char *s1, const size_t size1, char *s2,
						const size_t size2);
unsigned short		**init_matrix(t_data *data);
void				free_matrix(unsigned short **matrix, t_data *data);
unsigned short		**free_matrix_i(unsigned short **matrix, int i);
t_coin				find_largest_square(unsigned short **matrix, t_data *data);
unsigned int		ft_atoi(char *str, int digit_count);
void				ft_putchar(char c);
#endif