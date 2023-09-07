/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:52:37 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/07 15:25:10 by hrahmane         ###   ########.fr       */
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
	return (var->p.direction);
}
