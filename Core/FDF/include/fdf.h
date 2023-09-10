/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:29:12 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/06 10:35:34 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../mlx/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 1080
# define WIDTH 1920

typedef enum e_projection
{
	ISO,
	PARALLEL
}					t_projection;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				real_z;
	int32_t			color;
}					t_point;

typedef struct s_matrix
{
	t_point			**points;
	int				height;
	int				width;
	int				z_min;
	int				z_max;
}					t_matrix;

typedef struct s_camera
{
	t_projection	projection;
	int				shift_x;
	int				shift_y;
	int				zoom;
	double			angle_x;
	double			angle_y;
	double			angle_z;
}					t_camera;

typedef struct s_fdf
{
	t_matrix		*matrix;
	t_camera		*camera;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				steep;
}					t_fdf;

t_fdf				*init_fdf(int fd);
t_matrix			*map_parsing(int fd);
t_matrix			*map_error(char **split, t_matrix *matrix, int size);
t_point				project(t_point *point, t_fdf *fdf);
void				event_handler(void *param);
void				ft_reset_camera(t_camera *camera);
void				free_matrix(t_matrix *matrix, int size);
void				free_fdf(t_fdf *fdf);
void				draw(t_fdf *fdf);
int					i_part_num(float x);
float				f_part_num(float x);
float				rf_part_num(float x);
void				put_pixel(t_fdf *fdf, int x, int y, int32_t color);
t_point				point_to_draw(t_point *point);

#endif
