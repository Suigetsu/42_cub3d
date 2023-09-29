/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:52:37 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/29 20:24:51 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

float	get_direction(t_cub *var)
{
	if (var->p.dir == 'N')
		var->p.direction = 270 * var->p.radians;
	else if (var->p.dir == 'S')
		var->p.direction = 90 * var->p.radians;
	else if (var->p.dir == 'E')
		var->p.direction = 0;
	else if (var->p.dir == 'W')
		var->p.direction = 180 * var->p.radians;
	else
		return (0);
	var->p.dir = '\0';
	return (var->p.direction);
}

void	fix_any_angle(float	*angle)
{
	if (*angle < 0)
		*angle += 2 * M_PI;
	else if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
}
