/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_newdraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:50:30 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/19 16:39:22 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	cast_rays(t_cub3d *var, mlx_image_t *img)
{
	int		i;

	i = 0;
	int x0, x1, y0, y1;
	float wal_projct;
	float distance;
	float cor_dis;
	var->p.ray_angle = var->p.direction - 30;
	distance = ((var->x_max * T_SIZE) / 2) / tan(FOV / 2);
	printf("%f - %f\n", var->x_max * T_SIZE, var->y_max * T_SIZE);
	while (i < (var->x_max * T_SIZE))
	{
		fix_angle(var);
		get_vertical_distance(var, img);
		get_horizontal_distance(var, img);
		if (var->ray.horizon > var->ray.vertical)
		{
			var->ray.inter_x = var->ray.endx_v;
			var->ray.inter_y = var->ray.endy_v;
			var->ray.distance = var->ray.vertical;
		}
		else
		{
			var->ray.inter_x = var->ray.endx_h;
			var->ray.inter_y = var->ray.endy_h;
			var->ray.distance = var->ray.horizon;
		}
		// printf("distance: %f\n", var->ray.distance);
		cor_dis = var->ray.distance  * cos(var->p.ray_angle - var->p.direction); 
		wal_projct = (T_SIZE / cor_dis) * distance;
		x0 = i;
		x1 = i;
		y0 = ((var->y_max * T_SIZE) / 2) - (wal_projct / 2);
		y1 = ((var->y_max * T_SIZE) / 2) + (wal_projct / 2);
		while (y0 < y1)
		{
			if (y0 >= 0 && y0 < (var->y_max * T_SIZE))
				mlx_put_pixel(var->img, x0, y0, 0xFFFFFF);
			y0++;
		}
		// draw_line(var, img);
		var->p.ray_angle += FOV / (var->x_max * T_SIZE);
		i++;
	}
}

bool	is_up(t_cub3d *var)
{
	if (var->p.ray_angle > 0 && var->p.ray_angle <= 180)
		return (true);
	return (false);
}
bool	is_down(t_cub3d *var)
{
	if (var->p.ray_angle < 0 || var->p.ray_angle >= 180)
		return (true);
	return (false);
}

bool	is_left(t_cub3d *var)
{
	if (var->p.ray_angle > 90 && var->p.ray_angle < 270)
		return (true);
	return (false);
}

bool	is_right(t_cub3d *var)
{
	if (var->p.ray_angle < 90 || var->p.ray_angle > 270)
		return (true);
	return (false);
}

// void	draw_line(t_cub3d *var, mlx_image_t *img)
// {
// 	int	i;

// 	i = 0;
// 	var->ray.dx = (var->ray.inter_x - var->p.h);
// 	var->ray.dy = (var->ray.inter_y - var->p.k);
// 	if (abs(var->ray.dx) > abs(var->ray.dy))
// 		var->ray.step = abs(var->ray.dx);
// 	else
// 		var->ray.step = abs(var->ray.dy);
// 	var->ray.step_x = (float)var->ray.dx / var->ray.step;
// 	var->ray.step_y = (float)var->ray.dy / var->ray.step;
// 	var->ray.x = var->p.h;
// 	var->ray.y = var->p.k;
// 	while (i <= var->ray.step)
// 	{
// 		if (var->ray.x > 0 && var->ray.x < var->x_max * T_SIZE && \
// 			var->ray.y > 0 && var->ray.y < var->y_max * T_SIZE)
// 			mlx_put_pixel(img, var->ray.x, var->ray.y, 0x0000FFFF);
// 		var->ray.x += var->ray.step_x;
// 		var->ray.y += var->ray.step_y;
// 		i++;
// 	}
// }

// void	get_horizontal_distance(t_cub3d *var)
// {
// 	float	dx;
// 	float	dy;

// 	if (!is)
// }

void	get_horizontal_distance(t_cub3d *var, mlx_image_t *img)
{
	float	dx;
	float	dy;
	
	// printf("d = %f\n", var->p.ray_angle);
	if (!is_up(var))
	{
		var->ray.endy_h = (int)((var->p.k / T_SIZE)) * T_SIZE - 0.001;
		dy = T_SIZE * -1;
	}
	else
	{
		var->ray.endy_h = (int)((var->p.k / T_SIZE)) * T_SIZE + T_SIZE;
		dy = T_SIZE;
	}
	var->ray.endx_h = var->p.h + (var->p.k - var->ray.endy_h) / tan(var->p.ray_angle * RADIANS);
	dx = -dy / tan(var->p.ray_angle * RADIANS);
	// if (!is_left(var) && dx > 0)
	// 	dx *= -1;
	// else if (is_left(var) && dx < 0)
	// 	dx *= -1;
	// printf("%f - %f\n", var->ray.endx_h/T_SIZE, var->ray.endy_h/T_SIZE);
	while (var->ray.endy_h / T_SIZE >= 0 && var->ray.endy_h / T_SIZE < var->y_max 
			&& var->ray.endx_h / T_SIZE >= 0 && var->ray.endx_h / T_SIZE < var->x_max &&
			var->map[(int)var->ray.endy_h / T_SIZE][(int)var->ray.endx_h / T_SIZE] && \
		var->map[(int)(var->ray.endy_h) / T_SIZE][(int)var->ray.endx_h / T_SIZE] != '1')
	{
		var->ray.endx_h += dx;
		var->ray.endy_h += dy;
	}
	// printf("%f - %f\n", var->ray.endx_h/T_SIZE, var->ray.endy_h/T_SIZE);
	(void)img;
	// drawLineDDA(var->p.h, var->p.k, var->ray.endx_h, var->ray.endy_h, img, var);
	var->ray.horizon = sqrt(pow(var->p.h - var->ray.endx_h, 2) + pow(var->p.k - var->ray.endy_h, 2));
}

void	get_vertical_distance(t_cub3d *var, mlx_image_t *img)
{
	float	dx;
	float	dy;
	int		i;
	
	i = 1;
	dx = 0;
	// printf("d = %f\n", var->p.ray_angle);
	if (is_right(var))
	{
		var->ray.endx_v = (int)((var->p.h / T_SIZE)) * T_SIZE - 0.001;
		dx = T_SIZE * -1;
	}
	else if (is_left(var))
	{
		var->ray.endx_v = (int)((var->p.h / T_SIZE)) * T_SIZE + T_SIZE;
		dx = T_SIZE;
	}
	else
		i = 0;
	var->ray.endy_v = var->p.k + (var->p.h - var->ray.endx_v) * tan(var->p.ray_angle * RADIANS);
	dy = -dx * tan(var->p.ray_angle * RADIANS);
	// if (is_up(var) && dy > 0)
	// 	dy *= -1;
	// else if (!is_up(var) && dy < 0)
	// 	dy *= -1;
	// printf("%f - %f\n", var->ray.endx_v/T_SIZE, var->ray.endy_v/T_SIZE);
	// if (var->ray.endx_v < 0 || var->ray.endy_v < 0)
	// 	return ;
	while (i && var->ray.endy_v / T_SIZE >= 0 && var->ray.endy_v / T_SIZE < var->y_max 
			&& var->ray.endx_v / T_SIZE >= 0 && var->ray.endx_v / T_SIZE < var->x_max 
		&& var->map[(int)var->ray.endy_v / T_SIZE][(int)var->ray.endx_v / T_SIZE] && \
		var->map[(int)(var->ray.endy_v) / T_SIZE][(int)(var->ray.endx_v) / T_SIZE] != '1')
	{
		var->ray.endx_v += dx;
		var->ray.endy_v += dy;
	}
	// printf("%f - %f\n", var->ray.endx_v/T_SIZE, var->ray.endy_v/T_SIZE);
	// if (i)
		// drawLineDDA(var->p.h, var->p.k, var->ray.endx_v, var->ray.endy_v, img, var);
	(void)img;
	var->ray.vertical = sqrt(pow(var->p.h - var->ray.endx_v, 2) + pow(var->p.k - var->ray.endy_v, 2));
}
