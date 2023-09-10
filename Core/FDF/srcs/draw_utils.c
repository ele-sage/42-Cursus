/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:33:26 by ele-sage          #+#    #+#             */
/*   Updated: 2023/02/28 15:55:26 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	i_part_num(float x)
{
	return ((int)x);
}

float	f_part_num(float x)
{
	if (x > 0)
		return (x - i_part_num(x));
	else
		return (x - (i_part_num(x) + 1));
}

float	rf_part_num(float x)
{
	return (1 - f_part_num(x));
}

void	put_pixel(t_fdf *fdf, int x, int y, int32_t color)
{
	if (fdf->steep)
	{
		if (y >= 0 && y + 1 < WIDTH && x >= 0 && x < HEIGHT)
			mlx_put_pixel(fdf->img, y, x, color);
	}
	else
	{
		if (x >= 0 && x < WIDTH && y + 1 >= 0 && y + 1 < HEIGHT)
			mlx_put_pixel(fdf->img, x, y + 1, color);
	}
}

t_point	point_to_draw(t_point *point)
{
	t_point	new;

	new.x = point->x;
	new.y = point->y;
	new.z = point->z;
	new.real_z = point->z;
	return (new);
}
