/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:03:21 by ele-sage          #+#    #+#             */
/*   Updated: 2023/02/28 15:57:34 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	z_max_min(t_matrix *matrix)
{
	int	i;
	int	j;

	i = 0;
	matrix->z_max = matrix->points[0][0].z;
	matrix->z_min = matrix->points[0][0].z;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			if (matrix->points[i][j].z > matrix->z_max)
				matrix->z_max = matrix->points[i][j].z;
			if (matrix->points[i][j].z < matrix->z_min)
				matrix->z_min = matrix->points[i][j].z;
			j++;
		}
		i++;
	}
}

static t_matrix	*init_matrix(t_matrix *matrix, char **map)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	matrix->points = (t_point **)malloc(sizeof(t_point *) * matrix->height);
	if (!matrix->points)
		return (NULL);
	while (i < matrix->height)
	{
		j = -1;
		matrix->points[i] = (t_point *)malloc(sizeof(t_point) * matrix->width);
		if (!matrix->points[i])
			map_error(split, matrix, i);
		split = ft_split(map[i], ' ');
		while (++j < matrix->width)
		{
			matrix->points[i][j].x = j;
			matrix->points[i][j].y = i;
			matrix->points[i][j].z = ft_atoi(split[j]);
		}
		i++;
		ft_free_split(split);
	}
	return (matrix);
}

static t_matrix	*is_map_valid(t_matrix *matrix, char **map)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	if (!map[0])
		return (NULL);
	width = ft_count_word(map[0], ' ');
	while (map[i])
	{
		j = 0;
		if ((int)ft_count_word(map[i], ' ') != width)
			return (NULL);
		while (map[i][j])
		{
			if (map[i][j] != ' ' && !ft_isdigit(map[i][j]) && map[i][j] != '-')
				return (NULL);
			j++;
		}
		i++;
	}
	matrix->height = i;
	matrix->width = width;
	return (init_matrix(matrix, map));
}

t_matrix	*map_parsing(int fd)
{
	char		**map;
	char		*file;
	t_matrix	*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	file = ft_gnl_join(fd);
	map = ft_split(file, '\n');
	matrix = is_map_valid(matrix, map);
	free(file);
	ft_free_split(map);
	if (!matrix)
	{
		ft_printf("\n\nMap Error?????\n\n");
		free(matrix);
		return (NULL);
	}	
	z_max_min(matrix);
	return (matrix);
}
