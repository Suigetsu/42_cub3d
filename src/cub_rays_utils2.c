/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rays_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:35:13 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/29 20:47:44 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_texture(t_cub *var)
{
	while (var->ray.y0 < var->ray.y1)
	{
		var->y_step = (var->ray.y0 - var->ny) * \
			((float)var->txt[var->intxt]->height / var->wall_project);
		if (var->y_step < (int)var->txt[var->intxt]->height)
		{
			if (var->ray.y0 >= 0 && var->ray.y0 < (HEIGHT) && \
				(var->intxt == 1 || var->intxt == 2))
				mlx_put_pixel(var->img, var->ray.x0, var->ray.y0, \
				get_color(var->txt[var->intxt], var->txt[var->intxt]->width \
					- var->x_step, var->y_step));
			else if (var->ray.y0 >= 0 && var->ray.y0 < (HEIGHT) && \
				(var->intxt == 0 || var->intxt == 3))
			{
				mlx_put_pixel(var->img, var->ray.x0, var->ray.y0, \
				get_color(var->txt[var->intxt], var->x_step, var->y_step));
			}
		}
		var->ray.y0++;
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
	if (temp_x < 0 || temp_x > (int)var->x_max / T_SIZE || \
		temp_y < 0 || temp_y > (int)var->y_max / T_SIZE)
		return (0);
	if (var->map[temp_y][temp_x] == '1')
		return (1);
	return (0);
}
