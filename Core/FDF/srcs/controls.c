/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:17:34 by ele-sage          #+#    #+#             */
/*   Updated: 2023/02/27 20:07:26 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_close(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	free_fdf(fdf);
	mlx_terminate(fdf->mlx);
	exit(0);
}

static void	ft_move_rotate(t_fdf *fdf, int key)
{
	if (key == MLX_KEY_Q)
		fdf->camera->angle_y -= 0.1;
	else if (key == MLX_KEY_E)
		fdf->camera->angle_y += 0.1;
	else if (key == MLX_KEY_W)
		fdf->camera->angle_x -= 0.1;
	else if (key == MLX_KEY_S)
		fdf->camera->angle_x += 0.1;
	else if (key == MLX_KEY_A)
		fdf->camera->angle_z += 0.1;
	else if (key == MLX_KEY_D)
		fdf->camera->angle_z -= 0.1;
	if (key == MLX_KEY_UP)
		fdf->camera->shift_y += fdf->camera->zoom;
	else if (key == MLX_KEY_DOWN)
		fdf->camera->shift_y -= fdf->camera->zoom;
	else if (key == MLX_KEY_LEFT)
		fdf->camera->shift_x += fdf->camera->zoom;
	else if (key == MLX_KEY_RIGHT)
		fdf->camera->shift_x -= fdf->camera->zoom;
}

static void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	(void)(xdelta);
	fdf = (t_fdf *)param;
	if (ydelta > 0)
		fdf->camera->zoom += 1;
	else if (ydelta < 0)
		fdf->camera->zoom -= 1;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf);
}

static void	ft_key_press(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_close(fdf);
	else if (keydata.key == MLX_KEY_I)
		fdf->camera->projection = ISO;
	else if (keydata.key == MLX_KEY_P)
		fdf->camera->projection = PARALLEL;
	else if (keydata.key == MLX_KEY_R)
		ft_reset_camera(fdf->camera);
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E
		|| keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
		|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D
		|| keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		ft_move_rotate(fdf, keydata.key);
	draw(fdf);
}

void	event_handler(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_key_hook(fdf->mlx, ft_key_press, fdf);
	mlx_scroll_hook(fdf->mlx, ft_scroll, fdf);
	mlx_close_hook(fdf->mlx, ft_close, fdf);
}
