/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:15:04 by egervais          #+#    #+#             */
/*   Updated: 2023/10/19 16:33:47 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	intersect_tube(t_cylinder *cylinder, t_ray *ray, t_hit_info *hit_info)
{
	double		abc[3];
	t_equation	eq;

	intersect_tube_quadratic(cylinder, ray, abc);
	eq.a = abc[1] * abc[1] - 4.0 * abc[0] * abc[2];
	if (eq.a < 0 || abc[0] < 1e-6)
		return ;
	eq.a = sqrt(eq.a);
	eq.t1 = (-abc[1] - eq.a) / (2.0 * abc[0]);
	eq.t2 = (-abc[1] + eq.a) / (2.0 * abc[0]);
	eq.d = vec3_add(ray->pos, vec3_mul(ray->dir, eq.t1));
	eq.e = vec3_add(ray->pos, vec3_mul(ray->dir, eq.t2));
	eq.b = vec3_dot(vec3_sub(eq.d, cylinder->pos), cylinder->dir);
	eq.c = vec3_dot(vec3_sub(eq.e, cylinder->pos), cylinder->dir);
	if (eq.t1 >= 0 && hit_info->dist >= eq.t1 && fabs(eq.b) <= cylinder->height
		/ 2.0)
	{
		set_values(hit_info, eq.t1, ray, cylinder);
		return ;
	}
	if (eq.t2 >= 0 && hit_info->dist >= eq.t2 && fabs(eq.c) <= cylinder->height
		/ 2.0)
		set_values(hit_info, eq.t2, ray, cylinder);
}

void	intersect_disc(t_disk *disk, t_ray *ray,
					t_hit_info *hit_info, t_cylinder *cylinder)
{
	double	t;
	double	denom;
	t_vec3	oc;
	t_vec3	p;
	t_vec3	v;

	denom = vec3_dot(disk->dir, ray->dir);
	if (fabs(denom) > 1e-6)
	{
		oc = vec3_sub(disk->pos, ray->pos);
		t = vec3_dot(oc, disk->dir) / denom;
		if (t < 0 || hit_info->dist < t)
			return ;
		p = vec3_add(ray->pos, vec3_mul(ray->dir, t));
		v = vec3_sub(p, disk->pos);
		if (vec3_dot(v, v) > disk->radius * disk->radius)
			return ;
		hit_info->dist = t;
		hit_info->collided = true;
		hit_info->hit.pos = p;
		hit_info->hit.dir = disk->dir;
		hit_info->color = disk->color;
		hit_info->obj_hit = (void *)cylinder;
	}
}

void	normal_of_tube(t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_vec3	proj;
	t_vec3	oc;

	oc = vec3_sub(hit_info->hit.pos, cylinder->pos);
	proj = vec3_mul(cylinder->dir, vec3_dot(oc, cylinder->dir));
	hit_info->hit.dir = vec3_norm(vec3_sub(oc, proj));
}

void	intersect_tube_quadratic(t_cylinder *cylinder, t_ray *ray,
			double abc[3])
{
	t_vec3	ray_x_tube;
	t_vec3	dif_x_dir;

	ray_x_tube = vec3_cross(ray->dir, cylinder->dir);
	abc[0] = vec3_dot(ray_x_tube, ray_x_tube);
	dif_x_dir = vec3_cross(vec3_sub(ray->pos, cylinder->pos), cylinder->dir);
	abc[1] = 2.0 * vec3_dot(ray_x_tube, dif_x_dir);
	abc[2] = vec3_dot(dif_x_dir, dif_x_dir)
		- cylinder->radius * cylinder->radius;
}

void	hit_cylinder(t_cylinder *cylinder, t_ray ray, t_hit_info *hit_info)
{
	intersect_disc(&cylinder->disk[0], &ray, hit_info, cylinder);
	intersect_disc(&cylinder->disk[1], &ray, hit_info, cylinder);
	intersect_tube(cylinder, &ray, hit_info);
}
