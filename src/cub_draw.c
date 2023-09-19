/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:43:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/18 18:23:13 by hrahmane         ###   ########.fr       */
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

	var->p.radius = 3 * MINIMAP_SF;
	i = var->p.p_pos_y * MINIMAP_SF;
	j = var->p.p_pos_x * MINIMAP_SF;
	var->p.h = (var->p.p_pos_x + (T_SIZE / 2));
	var->p.k = (var->p.p_pos_y + (T_SIZE / 2));
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

// typedef struct t_utilis_vars
// {
// 	float	draw_x;
// 	float	draw_y;
// 	float	steps;
// 	float	dst_x;
// 	float	dst_y;
// 	int		i;
// }	t_utilis;

// void	draw_player_line_ray_mini_map(t_cub3d *vars, int color, mlx_image_t *img)
// {
// 	t_utilis	ut;

// 	ut.dst_x = (vars->ray.inter_x - vars->p.h);
// 	ut.dst_y = (vars->ray.inter_y - vars->p.k);
// 	printf("destination: %f - %f", ut.dst_x, ut.dst_y);
// 	ut.draw_x = vars->p.h;
// 	ut.draw_y = vars->p.k;
// 	if (fabs(ut.dst_y) > fabs(ut.dst_x))
// 		ut.steps = fabs(ut.dst_y);
// 	else
// 		ut.steps = fabs(ut.dst_x);
// 	ut.dst_x = (ut.dst_x / ut.steps);
// 	ut.dst_y = (ut.dst_y / ut.steps);
// 	ut.i = 0;
// 	while (ut.i <= ut.steps)
// 	{
// 		if (ut.draw_x > 0 && ut.draw_x < vars->x_max * T_SIZE && ut.draw_y > 0 && ut.draw_y < vars->y_max * T_SIZE)
// 			mlx_put_pixel(img, (int)ut.draw_x, (int)ut.draw_y, color);
// 		ut.draw_y += ut.dst_y;
// 		ut.draw_x += ut.dst_x;
// 		ut.i++;
// 	}
// }

// void	draw_line(mlx_image_t *img, t_cub3d *var, int color)
// {
// 	float	dx;
// 	float	dy;
// 	float	pixelx;
// 	float	pixely;
// 	int		pixels;

// 	if (!var->p.direction)
// 		var->p.direction = var->p.direction;
// 	dx = cos(var->p.direction);
// 	dy = sin(var->p.direction);
// 	var->ray.endy_h = (var->p.p_pos_y / T_SIZE) * T_SIZE - 0.01;
// 	var->ray.endx_h = var->p.p_pos_x + (var->p.p_pos_y - var->ray.endy_h) / tan(var->p.direction);
// 	// printf("%f - %f\n", var->ray.endy_h, var->ray.endx_h);
// 	// var->ray.horizon = (int)(var->ray.endy_h / sin(var->p.direction));
// 	while (var->map[(int)var->ray.endy_h / T_SIZE][(int)var->ray.endx_h / T_SIZE] != '1')
// 	{
// 		var->ray.endy_h -= T_SIZE;
// 		var->ray.endx_h += (T_SIZE / tan(var->p.direction));
// 		// printf("HORIZONTAL: %d - %d\n", var->ray.endy_h/T_SIZE, var->ray.endx_h/T_SIZE);
// 	}
// 	var->ray.horizon = sqrt(pow(var->p.p_pos_x - var->ray.endx_h, 2) + pow(var->p.p_pos_y - var->ray.endy_h, 2));
// 	var->ray.endx_v = (var->p.p_pos_x / T_SIZE) * (T_SIZE) -0.01;
// 	var->ray.endy_v = var->p.p_pos_y + ((var->ray.endx_v - var->p.p_pos_x) / tan(var->p.direction));
// 	// printf("%f - %f\n", var->ray.endy_v, var->ray.endx_v);
// 	// exit(0);
// 	// printf("%d - %d\n", var->ray.endy_v/T_SIZE, var->ray.endx_v/T_SIZE);
// 	while (var->map[(int)var->ray.endy_v / T_SIZE][(int)var->ray.endx_v / T_SIZE] != '1')
// 	{
// 		var->ray.endx_v += T_SIZE;
// 		var->ray.endy_v += (T_SIZE * tan(var->p.direction));
// 		if (var->ray.endy_v < 0)
// 			var->ray.endy_v = 0;
// 		// printf("VERTICAL: %d - %d\n", var->ray.endy_v/T_SIZE, var->ray.endx_v/T_SIZE);
// 	}
// 	var->ray.vertical = sqrt(pow(var->p.p_pos_x - var->ray.endx_v, 2) + pow(var->p.p_pos_y - var->ray.endy_v, 2));
// 	printf("hotrizon: %f - vertical: %f\n", var->ray.horizon, var->ray.vertical);
// 	if (var->ray.horizon < var->ray.vertical)
// 	{
// 		pixels = var->ray.horizon;
// 		var->ray.inter_x = var->ray.endx_h;
// 		var->ray.inter_y = var->ray.endy_h;
// 	}
// 	else
// 	{
// 		pixels = var->ray.vertical;
// 		var->ray.inter_x = var->ray.endx_v;
// 		var->ray.inter_y = var->ray.endy_v;
// 	}
// 	printf("%d\n", pixels);
// 	// exit(0);
// 	pixelx = var->p.h;
// 	pixely = var->p.k;
// 	// printf("%f, %f\n", pixelx, pixely);
// 	// // draw_line2(var, img, color);
// 	// while (pixels)
// 	// {
// 	// 	mlx_put_pixel(img, pixelx, pixely, color);
// 	// 	pixelx += dx;
// 	// 	pixely += dy;
// 	// 	--pixels;
// 	// }
// 	draw_player_line_ray_mini_map(var, color, img);
// }

void	draw_minimap(t_cub3d *var, mlx_image_t *img)
{
	var->y = 0;
	while (var->map[(int)var->y])
	{
		var->x = 0;
		while (var->map[(int)var->y][(int)var->x])
		{
			if (var->map[(int)var->y][(int)var->x] == '1')
				draw_pixels(var->x , var->y, 0x445FFFFF, img);
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
	// printf("%f - %f\n", var->p.h, var->p.k);
}
