/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:03:21 by ele-sage          #+#    #+#             */
/*   Updated: 2023/02/28 15:51:31 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_matrix *matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix->points[i]);
		i++;
	}
	free(matrix->points);
	free(matrix);
}

t_matrix	*map_error(char **split, t_matrix *matrix, int size)
{
	ft_free_split(split);
	free_matrix(matrix, size);
	exit(0);
	return (NULL);
}

void	free_fdf(t_fdf *fdf)
{
	free_matrix(fdf->matrix, fdf->matrix->height);
	free(fdf->camera);
}
