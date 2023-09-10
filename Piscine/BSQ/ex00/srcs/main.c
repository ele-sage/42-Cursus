/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:29:52 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/05 18:42:16 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manip.h"

void	ft_clear(t_data *data, unsigned short	**matrix)
{
	if (data->map)
		free(data->map);
	if (matrix)
		free_matrix(matrix, data);
}

int	solve(t_data *data, char *file)
{
	unsigned short	**matrix;

	init_data(data);
	if (!file)
	{
		if (read_stdin(data))
		{
			matrix = init_matrix(data);
			print_map_solution(*data, find_largest_square(matrix, data));
			ft_clear(data, matrix);
		}
	}
	else if (read_file(data, file))
	{
		matrix = init_matrix(data);
		print_map_solution(*data, find_largest_square(matrix, data));
		ft_clear(data, matrix);
	}	
	else
		write(1, "map error", 10);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc && solve(&data, argv[i]))
		{
			i++;
			putchar('\n');
			putchar('\n');
		}
		if (i < argc)
			return (1);
	}
	else
		return (solve(&data, NULL));
	return (0);
}
