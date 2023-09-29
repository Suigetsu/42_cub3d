/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_newdraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:50:30 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/29 19:52:49 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_line(t_cub *var, mlx_image_t *img)
{
	int	i;

	i = 0;
	var->ray.dx = var->ray.inter_x - (var->p.x);
	var->ray.dy = var->ray.inter_y - (var->p.y);
	if (abs(var->ray.dx) > abs(var->ray.dy))
		var->ray.step = abs(var->ray.dx);
	else
		var->ray.step = abs(var->ray.dy);
	var->ray.step_x = (float)var->ray.dx / var->ray.step;
	var->ray.step_y = (float)var->ray.dy / var->ray.step;
	var->ray.x = var->p.x;
	var->ray.y = var->p.y;
	while (i <= var->ray.step)
	{
		if (var->ray.x > 0 && var->ray.x < var->x_max - 1 && \
			var->ray.y > 0 && var->ray.y < var->y_max - 1)
			mlx_put_pixel(img, var->ray.x, var->ray.y, 0x0000FFFF);
		var->ray.x += var->ray.step_x;
		var->ray.y += var->ray.step_y;
		i++;
	}
}
