/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:43:07 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/27 08:04:55 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	move_mouse(int x, int y, void *param)
{
	t_cub	*var;
	int		delta_x;
	int		delta_y;
	
	var = (t_cub *)param;
	delta_x = x - (WIDTH / 2);
	delta_y = y - (HEIGHT / 2);
	
	var->p.direction += delta_x * var->p.rot_speed;
	return (0);
	// mlx_get_mouse_pos(var->mlx, (int)var->p.p_pos_x, (int)var->p.p_pos_y);
}