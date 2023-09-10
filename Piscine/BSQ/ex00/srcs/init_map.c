/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:16:56 by ele-sage          #+#    #+#             */
/*   Updated: 2022/12/14 20:39:35 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manip.h"

void	init_data(t_data *data)
{
	data->nb_lines = 0;
	data->len_lines = 0;
	data->map = NULL;
}

unsigned int	put_val_matrix2(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (data->map[i] != '\n')
		i++;
	return (i + 1);
}

void	put_val_matrix(t_data *data, unsigned short **matrix)
{
	unsigned int	i;
	unsigned int	j;
	int				k;

	i = put_val_matrix2(data);
	j = 0;
	k = 0;
	while (data->map[i] != '\0')
	{
		if (data->map[i] == '\n')
		{
			j = 0;
			k++;
		}
		else if (data->map[i] != '\n')
		{
			if (data->map[i] == data->obstacle)
				matrix[k][j++] = 0;
			else if (data->map[i] == data->empty)
				matrix[k][j++] = 1;
		}
		i++;
	}
}

unsigned short	**init_matrix(t_data *data)
{
	unsigned short	**matrix;
	unsigned int	i;

	matrix = malloc(sizeof(unsigned short *) * data->nb_lines);
	if (!matrix)
	{
		return (NULL);
	}
	i = 0;
	while (i < data->nb_lines)
	{
		matrix[i] = malloc(sizeof(unsigned short) * data->len_lines);
		if (!matrix[i])
			return (free_matrix_i(matrix, i));
		i++;
	}
	i = 0;
	put_val_matrix(data, matrix);
	return (matrix);
}
