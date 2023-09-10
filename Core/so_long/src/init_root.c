/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:59:09 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/22 18:17:46 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*static void	texture_load(t_root *root, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	if (*img == 0)
		root_destroy(0, "texture_init(): can't load texture", 0);
	(*img)->width = width;
	(*img)->height = height;
}

static void	init_texture(t_root *root)
{
	texture_load(root, &root->player, "./img/player.xpm");
	texture_load(root, &root->exit, "./img/helicopter.xpm");
	texture_load(root, &root->coll, "./img/gas.xpm");
	texture_load(root, &root->wall, "./img/wall.xpm");
	texture_load(root, &root->ground, "./img/sand.xpm");
}*/


static void	init_renderer(t_root *root)
{
	root->mlx = mlx_init();
	if (root->mlx == 0)
		root_destroy(root, "mlx_init(): can't load mlx", 0);
	root->mlx_win = mlx_new_window(root->mlx, root->game->width * 40,
			root->game->height * 40, "so_long");
	if (root->mlx_win == 0)
		root_destroy(root, "mlx_new_window(): can't create a window", 0);
	root->mlx_img = mlx_new_image(root->mlx, root->game->width * 40,
			root->game->height * 40);
	if (root->mlx_img == 0)
		root_destroy(root, "mlx_new_image(): can't create an image", 0);
}

t_root	*init_root(t_game *game)
{
	t_root			*root;

	root = malloc(sizeof(t_root));
	// if (root == 0)
	// 	root_destroy(0, "root_init(): malloc()", errno);
	root->game = game;
	root->mlx = 0;
	root->mlx_win = 0;
	root->mlx_img = 0;
	root->player = 0;
	root->exit = 0;
	root->coll = 0;
	root->wall = 0;
	root->ground = 0;
	init_renderer(root);
	//texture_init(root);
	return (root);
}