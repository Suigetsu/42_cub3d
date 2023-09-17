/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_newdraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:50:30 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/17 16:35:29 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_rays(t_cub3d *var, mlx_image_t *img)
{
	int		i;

	i = 0;
	var->p.ray_angle = var->p.direction - 30;
	while (i < (var->x_max * T_SIZE))
	{
		fix_angle(var);
		get_vertical_distance(var, img);
		get_horizontal_distance(var, img);
		// printf("h = %f, v =%f\n", var->ray.horizon, var->ray.vertical);
		if (var->ray.horizon > var->ray.vertical)
			drawLineDDA(var->p.h, var->p.k, var->ray.endx_v, var->ray.endy_v, img, var);
		else
			drawLineDDA(var->p.h, var->p.k, var->ray.endx_h, var->ray.endy_h, img, var);
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

void drawLineDDA(int x1, int y1, int x2, int y2, mlx_image_t *img, t_cub3d *var) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
		if (x > 0 && x < var->x_max * T_SIZE && y > 0 && y < var->y_max * T_SIZE)
        	mlx_put_pixel(img, x, y, 0x000000FF); // Assuming you're using a graphics library with putpixel function

        x += xIncrement;
        y += yIncrement;
    }
}

// void draw_line(t_cub3d *var, mlx_image_t *img)
// {
// 	var->ray.dx = abs((int)(var->ray.endx_h - var->p.h));
// 	var->ray.dy = abs((int)(var->ray.endy_h - var->p.k));
// 	if (var->p.h < var->ray.endx_h)
// 		var->ray.step_x = 1;
// 	else
// 		var->ray.step_x = -1;
// 	if (var->p.k < var->ray.endy_h)
// 		var->ray.step_y = 1;
// 	else
// 		var->ray.step_y = -1;
// 	if (var->ray.dx > var->ray.dy)
// 		var->ray.err = var->ray.dx / 2;
// 	else
// 		var->ray.err = (-var->ray.dy) / 2;
//     while (1)
//     {
//         mlx_put_pixel(img, var->p.h, var->p.k, 0xFFFFFF);
//         if (var->p.h == var->ray.endx_h && var->p.k == var->ray.endy_h)
//             break ;
//         var->ray.e2 = var->ray.err;
//         if (var->ray.e2 > -var->ray.dx)
//         {
//             var->ray.err -= var->ray.dy;
//             var->p.h += var->ray.step_x;
//         }
//         if (var->ray.e2 < var->ray.dy)
//         {
//             var->ray.err += var->ray.dx;
//             var->p.k += var->ray.step_y;
//         }
//     }
// }

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
