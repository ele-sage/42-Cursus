/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:54:17 by ele-sage          #+#    #+#             */
/*   Updated: 2022/12/14 20:15:39 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manip.h"

void	free_matrix(unsigned short **matrix, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_lines)
	{
		free(matrix[i]);
		i++;
	}
	if (data->len_lines != 0)
		free(matrix);
}

unsigned short	**free_matrix_i(unsigned short **matrix, int i)
{
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
	return (NULL);
}
