/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:25:04 by ele-sage          #+#    #+#             */
/*   Updated: 2023/02/28 15:54:59 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "fdf.h"

static void	set_grandient_inter_y(t_point point, t_point next, float *gradient,
		float *inter_y)
{
	float	dx;
	float	dy;

	dx = next.x - point.x;
	dy = next.y - point.y;
	*gradient = dy / dx;
	if (dx == 0.0f)
		*gradient = 1.f;
	*inter_y = point.y;
}

static void	draw_pixel(t_fdf *fdf, t_point point, t_point next)
{
	float	gradient;
	float	inter_y;
	int		x;

	x = point.x - 1;
	set_grandient_inter_y(point, next, &gradient, &inter_y);
	while (++x <= next.x)
	{
		put_pixel(fdf, x, i_part_num(inter_y) + 1,
			ft_get_color(x, point, next, f_part_num(inter_y)));
		put_pixel(fdf, x, i_part_num(inter_y),
			ft_get_color(x, point, next, rf_part_num(inter_y)));
		inter_y += gradient;
	}
}

static void	draw_line_aa(t_fdf *fdf, t_point point, t_point next)
{
	fdf->steep = ft_abs(next.y - point.y) > ft_abs(next.x - point.x);
	if (fdf->steep)
	{
		ft_swap(&point.x, &point.y);
		ft_swap(&next.x, &next.y);
	}
	if (point.x > next.x)
	{
		ft_swap(&point.x, &next.x);
		ft_swap(&point.y, &next.y);
	}
	if ((point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < WIDTH)
		|| (next.x >= 0 && next.x < WIDTH && next.y >= 0 && next.y < WIDTH))
		draw_pixel(fdf, point, next);
}

static void	draw_map(t_fdf *fdf, int i, int j)
{
	t_point	point;
	t_point	next_row;
	t_point	next_col;

	point = project(&fdf->matrix->points[i][j], fdf);
	if (j < fdf->matrix->width - 1)
	{
		next_col = project(&fdf->matrix->points[i][j + 1], fdf);
		draw_line_aa(fdf, point, next_col);
	}
	if (i < fdf->matrix->height - 1)
	{
		next_row = project(&fdf->matrix->points[i + 1][j], fdf);
		draw_line_aa(fdf, point, next_row);
	}
}

void	draw(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	ft_bzero(fdf->img->pixels, WIDTH * HEIGHT * 4);
	while (i < fdf->matrix->height)
	{
		j = 0;
		while (j < fdf->matrix->width)
		{
			draw_map(fdf, i, j);
			j++;
		}
		i++;
	}
}
