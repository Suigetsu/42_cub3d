/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:52:37 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/08 18:32:36 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_direction(t_cub3d *var)
{
	if (var->p.dir == 'N')
		var->p.direction = 90 * RADIANS;
	else if (var->p.dir == 'S')
		var->p.direction = 270 * RADIANS;
	else if (var->p.dir == 'E')
		var->p.direction = 360 * RADIANS;
	else if (var->p.dir == 'W')
		var->p.direction = 180 * RADIANS;
	else
		return (0);
	var->p.dir = '\0';
	return (var->p.direction);
}

void	rotate_player(t_cub3d *var, float angle)
{
	// printf("inside rotate\n");
	printf("old direction %f\n", var->p.direction);
	var->p.direction += angle;
	printf("new direction %f\n", var->p.direction);
	if (var->p.direction < 0)
		var->p.direction += 2 * PI;
	else if (var->p.direction >= 2 * PI)
        var->p.direction -= 2 * PI;
}

void	cast_rays(t_cub3d *var)
{
	int		i;

	i = 0;
	while (i < T_SIZE)
	{
		draw_line(var->img, var, 0xFFFFFD);
		var->p.ray_dir += FOV / T_SIZE;
		printf("%f\n", var->p.ray_dir);
		i++;
	}
}

