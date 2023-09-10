/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:07:47 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/06 10:31:46 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reset_camera(t_camera *camera)
{
	camera->shift_x = 0;
	camera->shift_y = 0;
	camera->zoom = 54;
	camera->angle_x = 0.f;
	camera->angle_y = 0.f;
	camera->angle_z = -1.f;
	camera->projection = ISO;
}

static t_camera	*init_camera(t_fdf *fdf)
{
	if (!fdf->matrix)
		return (NULL);
	fdf->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!fdf->camera)
	{
		free_matrix(fdf->matrix, fdf->matrix->height);
		return (NULL);
	}
	ft_reset_camera(fdf->camera);
	return (fdf->camera);
}

static void	draw_controls(t_fdf *fdf)
{
	mlx_put_string(fdf->mlx, "CONTROLS :", 20, 10);
	mlx_put_string(fdf->mlx, "_________", 20, 12);
	mlx_put_string(fdf->mlx, "ZOOM IN     : SCROLL UP", 20, 40);
	mlx_put_string(fdf->mlx, "ZOOM OUT    : SCROLL DOWN", 20, 60);
	mlx_put_string(fdf->mlx, "MOVE        : ARROWS", 20, 90);
	mlx_put_string(fdf->mlx, "ROTATE X    : Q / E", 20, 120);
	mlx_put_string(fdf->mlx, "ROTATE Z    : A / D", 20, 140);
	mlx_put_string(fdf->mlx, "ROTATE Y    : W / S", 20, 160);
	mlx_put_string(fdf->mlx, "CHANGE VIEW : I / P", 20, 190);
	mlx_put_string(fdf->mlx, "RESET       : R", 20, 220);
	mlx_put_string(fdf->mlx, "EXIT        : ESC", 20, 300);
}

static t_fdf	*fdf_error_control(t_fdf *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (fdf->mlx)
	{
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
		if (fdf->img)
		{
			draw_controls(fdf);
			return (fdf);
		}
		else
		{
			free_fdf(fdf);
			mlx_terminate(fdf->mlx);
		}
	}
	else
		free_fdf(fdf);
	return (NULL);
}

t_fdf	*init_fdf(int fd)
{
	t_fdf	*fdf;

	if (!fd)
		return (NULL);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->matrix = map_parsing(fd);
	if (!init_camera(fdf))
		return (NULL);
	return (fdf_error_control(fdf));
}
