/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:23:32 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/07 17:48:11 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move(t_cub3d *var, float x, float y)
{
	mlx_image_t	*img;
	
	img = NULL;
	var->x = 0;
	var->y = 0;
	while (var->map[(int)var->y])
	{
		var->x = 0;
		while (var->map[(int)var->y][(int)var->x])
		{
			if (var->map[(int)var->y][(int)var->x] == 'S')
			{
				var->map[(int)var->y][(int)var->x] = '0';
				var->map[(int)(var->y - y)][(int)(var->x - x)] = 'S';
				draw_minimap(var, img);
			}
			var->x++;
		}
		var->y++;
	}
}
