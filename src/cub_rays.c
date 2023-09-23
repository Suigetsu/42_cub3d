/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:34:39 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/23 16:00:35 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

uint32_t get_color(mlx_texture_t *txt, int x, int y)
{
	uint32_t color;
	color = ((uint32_t *)txt->pixels)[(txt->width * y) + x];
	return ((color & 0xFF000000) >> 24 | (color & 0x00FF0000) >> 8
		| (color & 0x0000FF00) << 8 | (color & 0x000000FF) << 24);
}


void	cast_rays(t_cub *var)
{
	int		i;
	int		y;
	// int		x0, x1, y0, y1;
	float	wall_project;
	float	distance;
	float	correct_dis;
	int		shading;
	
	distance = ((var->x_max) / 2) / tan(var->p.fov / 2);
	i = 0;
	fix_any_angle(&var->p.ray_angle);
	while (i < var->x_max)
	{
		var->p.ray_angle = var->p.direction - (var->p.fov / 2) + i * (float)var->p.fov / var->x_max;
		fix_any_angle(&var->p.ray_angle);
		horizontal_distance(var);
		vertical_distance(var);
		if (var->ray.vertical > var->ray.horizon)
		{
			if (var->ray.horizon == INT_MAX)
				break ;
			var->ray.inter_x = var->ray.endx_h;
			var->ray.inter_y = var->ray.endy_h;
			var->ray.distance = var->ray.horizon;
			var->ray.inter_axis = H_AXIS;
		}
		else
		{
			if (var->ray.vertical == INT_MAX)
				break ;
			var->ray.inter_x = var->ray.endx_v;
			var->ray.inter_y = var->ray.endy_v;
			var->ray.distance = var->ray.vertical;
			var->ray.inter_axis = V_AXIS;
		}
		correct_dis = var->ray.distance  * cos(var->p.ray_angle - var->p.direction); 
		wall_project = (T_SIZE / correct_dis) * distance;
		//put x0 y0 x1 y1 in the struct
		var->ray.x0 = i;
		var->ray.x1 = i;
		var->ray.y0 = ((var->y_max) / 2) - (wall_project / 2);
		var->ray.y1 = ((var->y_max) / 2) + (wall_project / 2);
		shading = 18000 / correct_dis;
		if (!var->ray.inter_axis)
			var->x_step = (var->txt->width / T_SIZE) * (var->ray.inter_y - (int)((var->ray.inter_y / T_SIZE) * T_SIZE));
		else
			var->x_step = (var->txt->width / T_SIZE) * (var->ray.inter_x - (int)((var->ray.inter_x / T_SIZE) * T_SIZE));
		y = var->ray.y0;
		while (y0 < y1)
		{
			var->y_step = (var->ray.y0 - y) * (var->txt->height / wall_project); 
			if (var->y_step < (int)var->txt->height)
				if (var->ray.y0 >= 0 && var->ray.y0 < (var->y_max))
					mlx_put_pixel(var->img, var->ray.x0, var->ray.y0, get_color(var->txt, var->x_step, var->y_step));
				var->ray.y0++;
		}
		// draw_3d_projection(var);
		i++;
	}
}

int	facing_up_down(t_cub *var)
{
	if (var->p.ray_angle >= M_PI && var->p.ray_angle < 2 * M_PI)
		return (1);
	else if (var->p.ray_angle > 0 && var->p.ray_angle < M_PI)
		return (0);
	return (-1);
}

int	facing_right_left(t_cub *var)
{
	if (var->p.ray_angle >= M_PI / 2 && var->p.ray_angle < 3 * M_PI / 2)
		return (1);
	else if (var->p.ray_angle < M_PI / 2 || var->p.ray_angle > 3 * M_PI / 2)
		return (0);
	return (-1);
}

int	checkwalls(t_cub *var, float x, float y, int flag)
{
	// printf("%d - %d\n", (int)(var->y_max - 1)/T_SIZE, (int)(var->x_max - 1)/T_SIZE);
	if (x < 0 || x > (int)(var->x_max - 1) || y < 0 || y > (int)(var->y_max - 1))
		return (0);
	if (flag == 0)
	{
		if (var->map[(int)((y - facing_up_down(var)) / T_SIZE)][(int)(x / T_SIZE)] == '1')
			return (1);
	}
	else
	{
		if (var->map[(int)(y / T_SIZE)][(int)((x - facing_right_left(var)) / T_SIZE)] == '1')
			return (1);
	}
	return (0);
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
	var->ray.endx_h = var->p.x + (var->ray.endy_h - var->p.y) / tan(var->p.ray_angle);
	if (facing_up_down(var) == 1)
		dy *= -1;
	if (facing_right_left(var) == 1 && dx > 0)
		dx *= -1;
	if (facing_right_left(var) == 0 && dx < 0)
		dx *= -1;
	// if (facing_up_down(var) == 1)
	// 	var->ray.endy_h -= 0.001;
	while (var->ray.endx_h >= 0 && var->ray.endx_h < var->x_max - 1 
		&& var->ray.endy_h >= 0 && var->ray.endy_h < var->y_max - 1)
	{
		// printf("%f - %f\n", var->ray.endx_h / T_SIZE, var->ray.endy_h / T_SIZE);
		if (checkwalls(var, var->ray.endx_h, var->ray.endy_h, 0))
			return (var->ray.horizon = sqrt(pow(var->p.x - var->ray.endx_h, 2) + pow(var->p.y - var->ray.endy_h, 2)));
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
	var->ray.endy_v = var->p.y + (var->ray.endx_v - var->p.x) * tan(var->p.ray_angle);
	if (facing_up_down(var) == 1 && dy > 0)
		dy *= -1;
	if (facing_up_down(var) == 0 && dy < 0)
		dy *= -1;
	if (facing_right_left(var) == 1)
		dx *= -1;
	// if (facing_right_left(var) == 1)
	// 	var->ray.endx_v -= 1;
	while (var->ray.endx_v >= 0 && var->ray.endx_v < var->x_max 
		&& var->ray.endy_v >= 0 && var->ray.endy_v < var->y_max)
	{
		if (var->map[(int)((var->ray.endy_v)/ T_SIZE)][(int)((var->ray.endx_v - facing_right_left(var)) / T_SIZE)] == '1')
		{
			// printf("%f - %f\n", var->ray.endx_v / T_SIZE, var->ray.endy_v / T_SIZE);
			return (var->ray.vertical = sqrt(pow(var->p.x - var->ray.endx_v, 2) + pow(var->p.y - var->ray.endy_v, 2)));
		}
		var->ray.endx_v += dx;
		var->ray.endy_v += dy;
	}
	return (var->ray.vertical = INT_MAX);
}
