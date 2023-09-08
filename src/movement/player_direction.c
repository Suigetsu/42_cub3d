/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:52:37 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/08 10:38:58 by hrahmane         ###   ########.fr       */
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
