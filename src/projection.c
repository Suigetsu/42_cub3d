/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:13:36 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/21 15:57:41 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_3d_projection(t_cub *var)
{
	int		i;
	int		x0, x1, y0, y1;
	float	wall_project;
	float	distance;
	float	correct_dis;
	
	i = -1;
	distance = ((var->x_max) / 2) / tan(FOV / 2);
	while (i < var->x_max)
	{
		correct_dis = var->ray.distance  * cos(var->p.ray_angle - var->p.direction); 
		wall_project = (T_SIZE / correct_dis) * distance;
		x0 = i;
		x1 = i;
		y0 = ((var->y_max) / 2) - (wall_project / 2);
		y1 = ((var->y_max) / 2) + (wall_project / 2);
		while (y0 < y1)
		{
			if (y0 >= 0 && y0 < (var->y))
				mlx_put_pixel(var->img, x0, y0, 0xFFFFFF);
			y0++;
		}
		var->p.ray_angle += FOV / (var->x_max);
		i++;
	}
}