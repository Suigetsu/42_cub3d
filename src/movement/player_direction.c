/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:52:37 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/19 19:31:22 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_direction(t_cub *var)
{
	if (var->p.dir == 'N')
		var->p.direction = 270;
	else if (var->p.dir == 'S')
		var->p.direction = 90;
	else if (var->p.dir == 'E')
		var->p.direction = 0;
	else if (var->p.dir == 'W')
		var->p.direction = 180;
	else
		return (0);
	var->p.dir = '\0';
	return (var->p.direction);
}

void	fix_any_angle(float	*angle)
{
	if (*angle < 0)
		*angle += 360;
	else if (*angle > 360)
		*angle -= 360;
}

void	fix_angle(t_cub *var)
{
	if (var->p.ray_angle < 0)
		var->p.ray_angle += 360;
	else if (var->p.ray_angle > 360)
        var->p.ray_angle -= 360;
}

// void	rotate_player(t_cub *var, float angle, int key)
// {
// 	if (key == MLX_KEY_RIGHT)
// 		angle *= -1;
// 	var->p.direction *= angle;
// 	// fix_angle(var);
// 	// draw_minimap(var, var->img);
// 	// draw_player_pixels(var, 0xFF378446, var->img);
// 	// cast_rays(var, var->img);
// }

// void	cast_rays(t_cub *var, mlx_image_t *img)
// {
// 	int		i;

// 	i = 0;
// 	var->p.ray_angle = var->p.direction + (30 * RADIANS);
// 	while (i < (var->x_max * T_SIZE))
// 	{
// 		get_horizontal_distance(var, img);
// 		var->p.ray_angle -= FOV / (var->x_max * T_SIZE);
// 		i++;
// 	}
// }

