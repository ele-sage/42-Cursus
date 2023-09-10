/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:08:28 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/22 15:34:23 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int free_matrix_i(char **matrix, int i)
{
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
	return (0);
}

int	set_game_infos(t_data *data, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->height = data->height;
	game->width = data->width;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->matrix[i][j] == 'P')
			{
				game->start.x = i;
				game->start.y = j;
			}
			else if (game->matrix[i][j] == 'E')
			{
				game->exit.x = i;
				game->exit.y = j;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	put_val_matrix(t_data *data, t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	game->nb_items = 0;
	while (data->map[k])
	{
		if (data->map[k] == '\n')
		{
			j = 0;
			i++;
		}
		else
		{
			if (data->map[k] == 'C')
				game->nb_items++;
			game->matrix[i][j] = data->map[k];
			j++;
		}
		k++;
	}
	return (1);
}

int init_matrix(t_data *data, t_game *game)
{
	int	i;

	game->matrix = malloc(sizeof(char *) * data->height);
	if (!game->matrix)
		return (0);
	i = 0;
	while (i < data->height)
	{
		game->matrix[i] = malloc(sizeof(char) * (data->width));
		if (!game->matrix[i])
			return (free_matrix_i(game->matrix, i));
		i++;
	}
	return (put_val_matrix(data, game));
}

int init_items(t_game *game)
{
	int i;
	int j;

	game->items = malloc(sizeof(t_coord) * game->nb_items);
	if(!game->items)
		return (0);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->matrix[i][j] == 'C')
			{
				game->items->x = i;
				game->items->y = j;
				game->items++;
			}
			j++;
		}
		i++;
	}
	game->items -= game->nb_items;
	return(1);
}

int	init_game(t_data *data, t_game *game)
{
	int is_game_init;

	is_game_init = 0;
	is_game_init += init_matrix(data, game);
	is_game_init += set_game_infos(data, game);
	is_game_init += init_items(game);
	if(is_game_init < 3)
		return (0);
	game->player.x = game->start.x;
	game->player.y = game->start.y;
	return (1);
}