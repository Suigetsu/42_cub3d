/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:34:39 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/24 17:00:00 by hrahmane         ###   ########.fr       */
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
	float		i;
	float		y;
	float	distance;
	float	correct_dis;
	
	distance = ((WIDTH) / 2) / tan((float)var->p.fov / 2);
	i = 0.0;
	fix_any_angle(&var->p.ray_angle);
	while (i < WIDTH)
	{
		var->p.ray_angle = var->p.direction - (var->p.fov / 2) + i * (float)var->p.fov / WIDTH;
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
		var->wall_project = (T_SIZE / correct_dis) * distance;
		var->ray.x0 = i;
		var->ray.x1 = i;
		var->ray.y0 = ((HEIGHT) / 2) - (var->wall_project / 2);
		var->ray.y1 = ((HEIGHT) / 2) + (var->wall_project / 2);
		int flag = -1;
		if (var->ray.inter_axis == 1 && facing_up_down(var) == 1)
		{
			var->x_step = (var->txt[0]->width / T_SIZE) * fmod(var->ray.inter_x, T_SIZE);
			flag = 0;
		}
		else if (var->ray.inter_axis == 1 && !facing_up_down(var) )
		{
			var->x_step = (var->txt[1]->width / T_SIZE) * fmod(var->ray.inter_x, T_SIZE);
			flag = 1;
		}
		else if (!var->ray.inter_axis && facing_right_left(var) == 1)
		{
			var->x_step = (var->txt[2]->width / T_SIZE) * fmod(var->ray.inter_y, T_SIZE);
			flag = 2;
		}
		else if (!var->ray.inter_axis && !facing_right_left(var))
		{
			var->x_step = (var->txt[3]->width / T_SIZE) * fmod(var->ray.inter_y, T_SIZE);
			flag = 3;
		}
		y = var->ray.y0;
		while (var->ray.y0 < var->ray.y1)
		{
			var->y_step = (var->ray.y0 - y) * ((float)var->txt[flag]->height / var->wall_project);
			if (var->y_step < (int)var->txt[flag]->height)
				if (var->ray.y0 >= 0 && var->ray.y0 < (HEIGHT))
					mlx_put_pixel(var->img, var->ray.x0, var->ray.y0, get_color(var->txt[flag], var->x_step, var->y_step));
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
	int	temp_x;
	int	temp_y;

	if (flag == 0)
		y -= facing_up_down(var);
	else
		x -= facing_right_left(var);
	temp_x = (int)x / T_SIZE;
	temp_y = (int)y / T_SIZE;
	if (temp_x < 0 || temp_x > (int)var->x_max / T_SIZE || temp_y < 0 || temp_y > (int)var->y_max / T_SIZE)
		return (0);
	if (var->map[temp_y][temp_x] == '1')
		return (1);
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
			return (var->ray.vertical = sqrt(pow(var->p.x - var->ray.endx_v, 2) + pow(var->p.y - var->ray.endy_v, 2)));
		var->ray.endx_v += dx;
		var->ray.endy_v += dy;
	}
	return (var->ray.vertical = INT_MAX);
}
