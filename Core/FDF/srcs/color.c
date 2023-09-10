/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:20:13 by ele-sage          #+#    #+#             */
/*   Updated: 2023/02/27 20:10:08 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "fdf.h"

int	get_default_color(int z, t_matrix *matrix)
{
	double			percent;
	unsigned int	max;

	max = matrix->z_max - matrix->z_min;
	percent = ((double)(z - matrix->z_min) / max);
	if (percent < 0.1)
		return (COLOR_SUNFLOWER);
	else if (percent < 0.2)
		return (COLOR_LIME);
	else if (percent < 0.3)
		return (COLOR_GREEN);
	else if (percent < 0.4)
		return (COLOR_SHAMROCK);
	else if (percent < 0.5)
		return (COLOR_TURQUOISE);
	else if (percent < 0.6)
		return (COLOR_SKY_BLUE);
	else if (percent < 0.7)
		return (COLOR_BLUE);
	else if (percent < 0.8)
		return (COLOR_BLUEBERRY);
	else if (percent < 0.9)
		return (COLOR_VIOLET);
	else
		return (COLOR_LAVENDER);
}

static int32_t	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int32_t	ft_get_color(int x, t_point s, t_point e, float factor)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	float	percent;

	percent = (float)ft_abs(x - s.x) / ft_abs(e.x - s.x);
	if (s.real_z < e.real_z)
	{
		r = ft_lerp(get_r(e.color), get_r(s.color), percent);
		g = ft_lerp(get_g(e.color), get_g(s.color), percent);
		b = ft_lerp(get_b(e.color), get_b(s.color), percent);
	}
	else
	{
		r = ft_lerp(get_r(s.color), get_r(e.color), percent);
		g = ft_lerp(get_g(s.color), get_g(e.color), percent);
		b = ft_lerp(get_b(s.color), get_b(e.color), percent);
	}
	return (get_rgba(r, g, b, 255 * factor));
}
