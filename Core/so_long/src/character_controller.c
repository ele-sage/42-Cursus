/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:50:00 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/22 18:21:04 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_input(int keycode, t_root *root)
{
	printf("%d\n", keycode);
	if (keycode == 13)
		; //w
	else if (keycode == 0)
		; //a
	else if (keycode == 1)
		; //s
	else if (keycode == 2)
		;                   //d
	else if (keycode == 53) //esq
	{
		mlx_destroy_window(root->mlx, root->mlx_win);
		exit(0);
	}
	return (0);
}

int is_valid_move(t_game *game, int moveX, int moveY)
{
	if(game->matrix[game->player.y + moveY][game->player.x + moveX] == '1')
		return (0);
	if(game->matrix[game->player.y + moveY][game->player.x + moveX] == 'E')
		if(game->nb_items != 0)
			return (0);
	if(game->matrix[game->player.y + moveY][game->player.x + moveX] == 'C')
		game->nb_items--;
	game->player.x += moveX;
	game->player.y += moveY;

	return (1);	
}