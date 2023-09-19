/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:34:39 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/19 21:19:01 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_rays(t_cub *var)
{
	int	i;

	i = 0;
	// var->p.ray_angle = 0;
	var->p.ray_angle = var->p.direction - 30;
	while (i < var->x_max)
	{
		fix_any_angle(&var->p.ray_angle);
		horizontal_distance(var);
		draw_line(var, var->img);
		var->p.ray_angle += var->p.fov / var->x_max;
		i++;
	}
}

int	facing_up_down(t_cub *var)
{
	if (var->p.ray_angle >= 180 && var->p.ray_angle < 360)
		return (1);
	else if (var->p.ray_angle > 0 && var->p.ray_angle < 180)
		return (0);
	return (-1);
}

int	facing_right_left(t_cub *var)
{
	if (var->p.ray_angle >= 90 && var->p.ray_angle < 270)
		return (1);
	else if (var->p.ray_angle < 9 || var->p.ray_angle > 270)
		return (0);
	return (-1);
}

float	horizontal_distance(t_cub *var)
{
	float	dx;
	float	dy;
	float	n_x;
	float	n_y;

	dy = T_SIZE;
	dx = T_SIZE / tan(var->p.ray_angle);
	var->ray.endy_h = (int)(var->p.y / T_SIZE) * T_SIZE;
	var->ray.endx_h = var->p.x + (var->p.y - var->ray.endy_h) / tan(var->p.ray_angle);
	if (facing_up_down(var) == 0)
	{
		var->ray.endy_h += dy;
		dy *= -1;
	}
	if (facing_right_left(var) == 1)
		dx *= -1;
	n_x = var->ray.endx_h;
	n_y = var->ray.endy_h;
	if (facing_up_down(var) == 1)
		var->ray.endy_h--;
	while (var->ray.endx_h / T_SIZE >= 0 && var->ray.endx_h / T_SIZE < var->x_max && var->ray.endy_h / T_SIZE >= 0 && var->ray.endy_h / T_SIZE < var->y_max)
	{
		printf("%f\n", var->ray.endx_h/T_SIZE);
		if (check_wall(var, var->ray.endx_h, var->ray.endy_h))
		{
			return (var->ray.horizon = sqrt(pow(var->p.x - var->ray.endx_h, 2) + pow(var->p.y - var->ray.endy_h, 2)));
		}
		var->ray.endx_h += dx;
		var->ray.endy_h += dy;
	}
	return (var->ray.horizon = INT_MAX);
}
