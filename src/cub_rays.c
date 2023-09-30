/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:34:39 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/30 15:58:57 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_rays(t_cub *var)
{
	var->intxt = -1;
	var->index = 0.0;
	var->dist = ((WIDTH) / 2) / tan(var->p.fov / 2);
	var->p.ray_angle = var->p.direction - (var->p.fov / 2);
	fix_any_angle(&var->p.ray_angle);
	while (var->index < WIDTH)
	{
		fix_any_angle(&var->p.ray_angle);
		if (get_right_distance(var))
			break ;
		var->corr_dis = var->ray.distance * \
			cos(var->p.ray_angle - var->p.direction);
		var->wall_project = (T_SIZE / var->corr_dis) * var->dist;
		var->ray.x0 = var->index;
		var->ray.y0 = ((HEIGHT) / 2) - (var->wall_project / 2);
		var->ray.y1 = ((HEIGHT) / 2) + (var->wall_project / 2);
		draw_textures(var);
		var->ny = var->ray.y0;
		put_texture(var);
		var->p.ray_angle += var->p.fov / WIDTH;
		var->index++;
	}
}

float	cal_distance(t_cub *var, int flag)
{
	if (flag == 0)
		return (var->ray.horizon = sqrt(pow(var->p.x - var->ray.endx_h, 2) \
			+ pow(var->p.y - var->ray.endy_h, 2)));
	return (var->ray.vertical = sqrt(pow(var->p.x - var->ray.endx_v, 2) \
		+ pow(var->p.y - var->ray.endy_v, 2)));
}

float	horizontal_distance(t_cub *var)
{
	float	dx;
	float	dy;

	dy = T_SIZE;
	dx = T_SIZE / tan(var->p.ray_angle);
	var->ray.endy_h = floor(var->p.y / T_SIZE) * T_SIZE;
	if (facing_up_down(var) == 0)
		var->ray.endy_h += dy;
	var->ray.endx_h = var->p.x + \
		(var->ray.endy_h - var->p.y) / tan(var->p.ray_angle);
	if (facing_up_down(var) == 1)
		dy *= -1;
	if (facing_right_left(var) == 1 && dx > 0)
		dx *= -1;
	if (facing_right_left(var) == 0 && dx < 0)
		dx *= -1;
	while (var->ray.endx_h >= 0 && var->ray.endx_h < var->x_max - 1 
		&& var->ray.endy_h >= 0 && var->ray.endy_h < var->y_max - 1)
	{
		if (checkwalls(var, var->ray.endx_h, var->ray.endy_h, 0))
			return (cal_distance(var, 0));
		var->ray.endx_h += dx;
		var->ray.endy_h += dy;
	}
	return (var->ray.horizon = INT_MAX);
}

float	vertical_distance(t_cub *var)
{
	float	dx;
	float	dy;

	dx = T_SIZE;
	dy = T_SIZE * tan(var->p.ray_angle);
	var->ray.endx_v = floor(var->p.x / T_SIZE) * T_SIZE;
	if (facing_right_left(var) == 0)
		var->ray.endx_v += dx;
	var->ray.endy_v = var->p.y + \
		(var->ray.endx_v - var->p.x) * tan(var->p.ray_angle);
	if (facing_up_down(var) == 1 && dy > 0)
		dy *= -1;
	if (facing_up_down(var) == 0 && dy < 0)
		dy *= -1;
	if (facing_right_left(var) == 1)
		dx *= -1;
	while (var->ray.endx_v >= 0 && var->ray.endx_v < var->x_max 
		&& var->ray.endy_v >= 0 && var->ray.endy_v < var->y_max)
	{
		if (checkwalls(var, var->ray.endx_v, var->ray.endy_v, 1))
			return (cal_distance(var, 1));
		var->ray.endx_v += dx;
		var->ray.endy_v += dy;
	}
	return (var->ray.vertical = INT_MAX);
}
