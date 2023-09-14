/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:43:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/14 11:48:44 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixels(float x, float y, int color, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < T_SIZE)
	{
		j = 0;
		while (j < T_SIZE)
		{
			mlx_put_pixel(img, (x * T_SIZE) + i, (y * T_SIZE) + j, color);
			if (j == T_SIZE - 1)
				mlx_put_pixel(img, (x * T_SIZE) + i, (y * T_SIZE) + j, 0);
			if (i == T_SIZE - 1)
				mlx_put_pixel(img, (x * T_SIZE) + i, (y * T_SIZE) + j, 0);
			j++;
		}
		i++;
	}
}

void	draw_player_pixels(t_cub3d *var, int color, mlx_image_t *img)
{
	float	i;
	float	j;

	var->p.radius = 3;
	i = var->p.p_pos_y;
	j = var->p.p_pos_x;
	var->p.h = var->p.p_pos_x + (T_SIZE / 2);
	var->p.k = var->p.p_pos_y + (T_SIZE / 2);
	while (i < var->p.p_pos_y + T_SIZE)
	{
		j = var->p.p_pos_x;
		while (j < var->p.p_pos_x + T_SIZE)
		{
			if (pow(j - var->p.h, 2) + \
				pow(i - var->p.k, 2) <= pow(var->p.radius, 2))
				mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_line(mlx_image_t *img, t_cub3d *var, int color)
{
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	int		err;
	int		err2;
	
	dx = fabs(var->p.end_x - var->p.h);
	if (var->p.h < var->p.end_x)
		sx = 1;
	else
		sx = -1;
	dy = -fabs(var->p.end_y - var->p.k);
	if(var->p.k < var->p.end_y)
		sy = 1;
	else
		sy = -1;
	
	err = dx + dy;
	while (1)
	{
		mlx_put_pixel(img, var->p.h, var->p.k, color);
		if (var->p.h == var->p.end_x && var->p.k == var->p.end_y)
			break;
		err2 = 2 * err;
		if(err2 >= dy)
		{
			if (var->p.h == var->p.end_x)
				break;
			err += dy;
			var->p.h += sx;
		}
		if (err2 <= dx)
		{
			if (var->p.k == var->p.end_y)
				break;
			err += dx;
			var->p.k += sy;
		}
	}
	
}

void	draw_minimap(t_cub3d *var, mlx_image_t *img)
{
	var->y = 0;
	while (var->map[(int)var->y])
	{
		var->x = 0;
		while (var->map[(int)var->y][(int)var->x])
		{
			if (var->map[(int)var->y][(int)var->x] == '1')
				draw_pixels(var->x, var->y, 0x445FFFFF, img);
			else if (var->map[(int)var->y][(int)var->x] == '0')
				draw_pixels(var->x, var->y, 0xFFFFFFFF, img);
			else if (var->map[(int)var->y][(int)var->x] == ' ')
				draw_pixels(var->x, var->y, 0x00000000, img);
			else
				draw_pixels(var->x, var->y, 0xFFFFFFFF, img);
			var->x++;
		}
		var->y++;
	}
}
