/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:55:53 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/22 16:05:00 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <assert.h>

void	look_up_and_left(t_imatrix *matrix, int i, int j, t_label *label)
{
	int	up;
	int	left;

	up = 0;
	left = 0;
	if (i)
		up = matrix->matrix[i - 1][j];
	if (j)
		left = matrix->matrix[i][j - 1];
	if ((!!up + !!left) == 0)
		matrix->matrix[i][j] = uf_make_set(label);
	else if ((!!up + !!left) == 1)
		matrix->matrix[i][j] = max(up, left);
	else if ((!!up + !!left) == 2)
		matrix->matrix[i][j] = uf_union(up, left, label);
}

int	init_to_zero(t_imatrix *matrix, int *new_labels, t_label *label)
{
	int	total_clusters;
	int	x;
	int	i;
	int	j;

	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			if (matrix->matrix[i][j])
			{
				x = uf_find(matrix->matrix[i][j], label);
				if (new_labels[x] == 0)
				{
					new_labels[0]++;
					new_labels[x] = new_labels[0];
				}
				matrix->matrix[i][j] = new_labels[x];
			}
			j++;
		}
		i++;
	}
	total_clusters = new_labels[0];
	free(new_labels);
	return (total_clusters);
}

int	hoshen_kopelman(t_imatrix *matrix, t_label *label)
{
	int	total_clusters;
	int	*new_labels;
	int	i;
	int	j;

	uf_initialize(matrix->height * matrix->width / 2, label);
	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			if (matrix->matrix[i][j])
				look_up_and_left(matrix, i, j, label);
			j++;
		}
		i++;
	}
	new_labels = calloc(sizeof(int), label->n_labels);
	total_clusters = init_to_zero(matrix, new_labels, label);
	uf_done(label);
	return (total_clusters);
}

int	is_start_items_exit_connectable(t_game *game, t_imatrix *matrix)
{
	int	i;

	i = 0;
	if (matrix->matrix[game->start.x][game->start.y] != matrix->matrix[game->exit.x][game->exit.y])
		return (0);
	while (i < game->nb_items)
	{
		if (matrix->matrix[game->start.x][game->start.y] != matrix->matrix[game->items[i].x][game->items[i].y])
			return (0);
		i++;
	}
	return (1);
}

void	init_label_matrix(t_game *game, t_imatrix *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			if (game->matrix[i][j] == '1')
				matrix->matrix[i][j] = 0;
			else
				matrix->matrix[i][j] = 1;
			j++;
		}
		i++;
	}
}

int	valid_path(t_game *game)
{
	t_label label;
	t_imatrix imatrix;
	int game_valide;

	imatrix.matrix = (int **)calloc(game->height, sizeof(int *));
	for (int i = 0; i < game->height; i++)
		imatrix.matrix[i] = (int *)calloc(game->width, sizeof(int));
	label.n_labels = (game->height * game->width);
	label.labels = (int *)calloc(label.n_labels, sizeof(int));
	label.n_labels = 0;
	imatrix.height = game->height;
	imatrix.width = game->width;
	init_label_matrix(game, &imatrix);
	game_valide = hoshen_kopelman(&imatrix, &label);

	for (int i = 0; i < imatrix.height; i++)
	{
		for (int j = 0; j < imatrix.width; j++)
		{
			printf("%d ", imatrix.matrix[i][j]);
		}
		printf("\n");
	}
	game_valide = is_start_items_exit_connectable(game, &imatrix);
	for (int i = 0; i < imatrix.width; i++)
		free(imatrix.matrix[i]);
	free(imatrix.matrix);
	return (game_valide);
}