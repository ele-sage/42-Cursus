/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_struct_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:01:57 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/22 18:29:20 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	root_destroy(t_root *root, char *errmsg, int errnum)
{
	(void) errmsg;
	(void) errnum;
	if (root != 0)
	{
		if (root->ground != 0)
			mlx_destroy_image(root->mlx, root->ground);
		if (root->wall != 0)
			mlx_destroy_image(root->mlx, root->wall);
		if (root->coll != 0)
			mlx_destroy_image(root->mlx, root->coll);
		if (root->exit != 0)
			mlx_destroy_image(root->mlx, root->exit);
		if (root->player != 0)
			mlx_destroy_image(root->mlx, root->player);
		if (root->mlx_img != 0)
			mlx_destroy_image(root->mlx, root->mlx_img);
		if (root->mlx_win != 0)
			mlx_destroy_window(root->mlx, root->mlx_win);
		if (root->mlx != 0)
			mlx_destroy_display(root->mlx);
		if (root->game != 0)
			game_destroy(root->game);
		free(root);
	}
	//die(errmsg, errnum);
}

void	game_destroy(t_game *game)
{
	int				i;
	if (game != 0)
	{
		if (game->matrix != 0)
		{
			i = 0;
			while (i < game->height)
				free(game->matrix[i++]);
			free(game->matrix);
		}
	}
	if(game->items != 0)
		free(game->items);
}