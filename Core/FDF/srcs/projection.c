/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:12:24 by ele-sage          #+#    #+#             */
/*   Updated: 2023/02/28 15:58:34 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "fdf.h"
#include <math.h>

static void	rotate(int *x, int *y, int *z, t_camera *camera)
{
	float	previous_x;
	float	previous_y;

	previous_y = *y;
	*y = previous_y * cos(camera->angle_x) + *z * sin(camera->angle_x);
	*z = -previous_y * sin(camera->angle_x) + *z * cos(camera->angle_x);
	previous_x = *x;
	*x = previous_x * cos(camera->angle_y) + *z * sin(camera->angle_y);
	*z = -previous_x * sin(camera->angle_y) + *z * cos(camera->angle_y);
	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(camera->angle_z) - previous_y * sin(camera->angle_z);
	*y = previous_x * sin(camera->angle_z) + previous_y * cos(camera->angle_z);
}

static void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point	project(t_point *point, t_fdf *fdf)
{
	t_point	p;

	p = point_to_draw(point);
	p.color = get_default_color(p.z, fdf->matrix);
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom;
	p.x -= (fdf->matrix->width * fdf->camera->zoom) / 2;
	p.y -= (fdf->matrix->height * fdf->camera->zoom) / 2;
	rotate(&p.x, &p.y, &p.z, fdf->camera);
	if (fdf->camera->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += WIDTH / 2 + fdf->camera->shift_x;
	p.y += (HEIGHT + fdf->matrix->height * fdf->camera->zoom) / 2
		+ fdf->camera->shift_y;
	return (p);
}
