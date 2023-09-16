/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_newdraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:50:30 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/16 20:55:17 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_rays(t_cub3d *var, mlx_image_t *img)
{
	int		i;

	i = 0;
	var->p.ray_angle = var->p.direction - (30 * RADIANS);
	while (i < (var->x_max * T_SIZE))
	{
		get_horizontal_distance(var, img);
		var->p.ray_angle += FOV / (var->x_max * T_SIZE);
		i++;
	}
}

bool	is_up(t_cub3d *var)
{
	if (var->p.ray_angle < 2 * M_PI && var->p.ray_angle >= M_PI)
		return (true);
	return (false);
}
bool	is_left(t_cub3d *var)
{
	if (var->p.ray_angle > M_PI / 2 && var->p.ray_angle < (3 * M_PI) / 2)
		return (true);
	return (false);
}

void draw_line(t_cub3d *var, mlx_image_t *img)
{
	var->ray.dx = fabsf(var->ray.endx_h - var->p.h);
	var->ray.dy = fabsf(var->ray.endy_h - var->p.k);
	if (var->p.h < var->ray.endx_h)
		var->ray.step_x = 1;
	else
		var->ray.step_x = -1;
	if (var->p.k < var->ray.endy_h)
		var->ray.step_y = 1;
	else
		var->ray.step_y = -1;
	if (var->ray.dx > var->ray.dy)
		var->ray.err = var->ray.dx / 2;
	else
		var->ray.err = (-var->ray.dy) / 2;
    while (1)
    {
        mlx_put_pixel(img, var->p.h, var->p.k, 0xFFFFFF);
        if (var->p.h == var->ray.endx_h && var->p.k == var->ray.endy_h)
            break ;
        var->ray.e2 = var->ray.err;
        if (var->ray.e2 > -var->ray.dx)
        {
            var->ray.err -= var->ray.dy;
            var->p.h += var->ray.step_x;
        }
        if (var->ray.e2 < var->ray.dy)
        {
            var->ray.err += var->ray.dx;
            var->p.k += var->ray.step_y;
        }
    }
}

// void test_draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1)
// {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx, sy;

//     if (x0 < x1) {
//         sx = 1;
//     } else {
//         sx = -1;
//     }

//     if (y0 < y1) {
//         sy = 1;
//     } else {
//         sy = -1;
//     }

//     int err;
//     if (dx > dy) {
//         err = dx / 2;
//     } else {
//         err = -dy / 2;
//     }

//     int e2;

//     while (1)
//     {
//         mlx_put_pixel(img, x0, y0, 0x00000000); // Assuming white color

//         if (x0 == x1 && y0 == y1)
//             break;

//         e2 = err;
//         if (e2 > -dx)
//         {
//             err -= dy;
//             x0 += sx;
//         }

//         if (e2 < dy)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }

void	get_horizontal_distance(t_cub3d *var, mlx_image_t *img)
{
	float	dx;
	float	dy;
	int		cx;
	int		cy;
	
	dx = T_SIZE / tan(var->p.ray_angle);
	if (is_up(var))
	{
		var->ray.endy_h = (int)((var->p.k / T_SIZE)) * T_SIZE;
		dy = T_SIZE;
	}
	else
	{
		var->ray.endy_h = (int)((var->p.k / T_SIZE)) * T_SIZE + T_SIZE;
		dy = T_SIZE * -1;
	}
	var->ray.endx_h = var->p.h + (var->p.k - var->ray.endy_h) / tan(var->p.ray_angle);
	if (is_left(var) && dx > 0)
		dx *= -1;
	else if (!is_left(var) && dx < 0)
		dx *= -1;
	cx = var->ray.endx_h + dx;
	cy = var->ray.endy_h + dy;
	while (var->map[(int)var->ray.endy_h / T_SIZE][(int)var->ray.endx_h / T_SIZE] != '1' && var->map[(int)var->ray.endy_h / T_SIZE][(int)var->ray.endx_h / T_SIZE])
	{
		var->ray.endx_h += dx;
		var->ray.endy_h += dy;
	}
	printf("%f - %f\n", var->ray.endx_h/T_SIZE, var->ray.endy_h/T_SIZE);
	// (void)img;
	draw_line(var, img);
}
