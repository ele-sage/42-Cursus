/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:40:03 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/22 16:04:50 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <assert.h>

int	uf_find(int x, t_label *label)
{
	int	y;
	int	z;

	y = x;
	while (label->labels[y] != y)
		y = label->labels[y];
	while (label->labels[x] != x)
	{
		z = label->labels[x];
		label->labels[x] = y;
		x = z;
	}
	return (y);
}

int	uf_union(int x, int y, t_label *label)
{
	return (label->labels[uf_find(x, label)] = uf_find(y, label));
}

int	uf_make_set(t_label *label)
{
	label->labels[0]++;
	assert(label->labels[0] < label->n_labels);
	label->labels[label->labels[0]] = label->labels[0];
	return (label->labels[0]);
}

void	uf_initialize(int max_labels, t_label *label)
{
	label->n_labels = max_labels;
	label->labels = calloc(sizeof(int), label->n_labels);
	label->labels[0] = 0;
}

/*  uf_done frees the memory used by the union-find data structures */

void	uf_done(t_label *label)
{
	label->n_labels = 0;
	free(label->labels);
	label->labels = 0;
}