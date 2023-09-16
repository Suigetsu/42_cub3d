/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:10:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/16 11:41:04 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void    init_arg_line(t_cub3d *arg)
{
    arg->ray.dx = fabsf(arg->ray.inter_x - arg->p.h);
    arg->ray.dy = fabsf(arg->ray.inter_y - arg->p.k);
    if (arg->p.h < arg->ray.inter_x)
        arg->ray.sx = 1;
    else
        arg->ray.sx = -1;
    if (arg->p.k < arg->ray.inter_y)
        arg->ray.sy = 1;
    else
        arg->ray.sy = -1;
    if (arg->ray.dx > arg->ray.dy)
        arg->ray.err = arg->ray.dx / 2;
    else
        arg->ray.err = -arg->ray.dy / 2;
}

void    draw_line2(t_cub3d *arg, mlx_image_t *image, int color)
{
    init_arg_line(arg);
    while (1)
    {
        mlx_put_pixel(image, arg->p.h, arg->p.k, color);
        if (arg->p.h == arg->ray.inter_x && arg->p.k == arg->ray.inter_y)
            break ;
        arg->ray.e2 = arg->ray.err;
        if (arg->ray.e2 > -arg->ray.dx)
        {
            arg->ray.err -= arg->ray.dy;
            arg->p.h += arg->ray.sx;
        }
        if (arg->ray.e2 < arg->ray.dy)
        {
            arg->ray.err += arg->ray.dx;
            arg->p.k += arg->ray.sy;
        }
    }
}

// void    draw_line_bresenham(mlx_image_t *img, t_cub3d *var, int color)
// {
// 	float    dx;
// 	float    dy;
// 	int        step_x;
// 	int        step_y;
// 	int        err;
// 	int        err2;
	
// 	dx = fabs(var->p.end_x - var->p.h);
// 	if (var->p.h < var->p.end_x)
// 		step_x = 1;
// 	else
// 		step_x = -1;
// 	dy = -fabs(var->p.end_y - var->p.k);
// 	if(var->p.k < var->p.end_y)
// 		step_y = 1;
// 	else
// 		step_y = -1;
// 	err = dx + dy;
// 	while (1)
// 	{
// 		mlx_put_pixel(img, var->p.h, var->p.k, color);
// 		if ((var->p.h == var->p.end_x && var->p.k == var->p.end_y))
// 			break;
// 		err2 = 2 * err;
// 		if(err2 >= dy)
// 		{
// 			if (var->p.h == var->p.end_x)
// 				break;
// 			err += dy;
// 			var->p.h += step_x;
// 		}
// 		if (err2 <= dx)
// 		{
// 			if (var->p.k == var->p.end_y)
// 				break;
// 			err += dx;
// 			var->p.k += step_y;
// 		}
// 	}
// }
