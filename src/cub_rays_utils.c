/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rays_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:32:31 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/29 20:27:10 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

uint32_t	get_color(mlx_texture_t *txt, int x, int y)
{
	uint32_t	color;

	color = ((uint32_t *)txt->pixels)[(txt->width * y) + x];
	return ((color & 0xFF000000) >> 24 | (color & 0x00FF0000) >> 8
		| (color & 0x0000FF00) << 8 | (color & 0x000000FF) << 24);
}

int	get_right_distance(t_cub *var)
{
	horizontal_distance(var);
	vertical_distance(var);
	if (var->ray.vertical > var->ray.horizon)
	{
		if (var->ray.horizon == INT_MAX)
			return (1);
		var->ray.inter_x = var->ray.endx_h;
		var->ray.inter_y = var->ray.endy_h;
		var->ray.distance = var->ray.horizon;
		var->ray.inter_axis = H_AXIS;
	}
	else
	{
		if (var->ray.vertical == INT_MAX)
			return (1);
		var->ray.inter_x = var->ray.endx_v;
		var->ray.inter_y = var->ray.endy_v;
		var->ray.distance = var->ray.vertical;
		var->ray.inter_axis = V_AXIS;
	}
	return (0);
}
