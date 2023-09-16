/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:52:37 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/16 10:31:32 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_direction(t_cub3d *var)
{
	if (var->p.dir == 'N')
		var->p.direction = 270 * (float)RADIANS;
	else if (var->p.dir == 'S')
		var->p.direction = 90 * (float)RADIANS;
	else if (var->p.dir == 'E')
		var->p.direction = 0 * (float)RADIANS;
	else if (var->p.dir == 'W')
		var->p.direction = 180 * (float)RADIANS;
	else
		return (0);
	return (var->p.direction);
}

void	fix_angle(t_cub3d *var)
{
	if (var->p.direction < 0)
		var->p.direction += 360;
	else if (var->p.direction > 360)
        var->p.direction -= 360;
}

void	rotate_player(t_cub3d *var, float angle, int key)
{
	if (key == MLX_KEY_RIGHT)
		angle *= -1;
	var->p.direction *= angle;
	// fix_angle(var);
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	// cast_rays(var);
}

void	cast_rays(t_cub3d *var)
{
	int		i;

	i = 0;
	var->p.ray_dir = var->p.direction + (30 * RADIANS);
	while (i < (var->x_max * T_SIZE))
	{
		draw_line(var->img, var, 0xFFFFFD);
		var->p.ray_dir -= FOV / (var->x_max * T_SIZE);
		i++;
	}
}

