/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bottons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:25:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/29 19:51:58 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_wall(t_cub *var, float x, float y)
{
	if (y / T_SIZE < 0 || x / T_SIZE < 0 || y / T_SIZE > \
		(var->y_max / T_SIZE) - 1 || x / T_SIZE > (var->x_max / T_SIZE) - 1)
		return (true);
	if (var->map[(int)(y / T_SIZE)][(int)(x / T_SIZE)] == '1')
		return (true);
	return (false);
}

int	up_move(t_cub *var)
{
	if (check_wall(var, var->p.x, \
		var->p.y + sinf(var->p.direction) * var->p.move_speed * 5) || \
		check_wall(var, var->p.x + cosf(var->p.direction) * \
		var->p.move_speed * 5, var->p.y))
		return (0);
	var->p.p_pos_x += cosf(var->p.direction) * var->p.move_speed;
	var->p.p_pos_y += sinf(var->p.direction) * var->p.move_speed;
	return (1);
}

int	down_move(t_cub *var)
{
	if (check_wall(var, var->p.x - cosf(var->p.direction) * \
		var->p.move_speed * 5, var->p.y) || \
		check_wall(var, var->p.x, var->p.y - sinf(var->p.direction) \
		* var->p.move_speed) * 5)
		return (0);
	var->p.p_pos_x -= cosf(var->p.direction) * var->p.move_speed;
	var->p.p_pos_y -= sinf(var->p.direction) * var->p.move_speed;
	return (1);
}

int	right_move(t_cub *var)
{
	if (check_wall(var, var->p.x + cosf((var->p.direction + M_PI / 2)) * \
		var->p.move_speed * 5, var->p.y) || \
		check_wall(var, var->p.x, var->p.y + \
		sinf((var->p.direction + M_PI / 2)) * var->p.move_speed) * 5)
		return (0);
	var->p.p_pos_x += cosf((var->p.direction + M_PI / 2)) * var->p.move_speed;
	var->p.p_pos_y += sinf((var->p.direction + M_PI / 2)) * var->p.move_speed;
	return (1);
}

int	left_move(t_cub *var)
{
	if (check_wall(var, var->p.x - cosf((var->p.direction + M_PI / 2)) * \
		var->p.move_speed * 5, var->p.y) || \
		check_wall(var, var->p.x, var->p.y - \
		sinf((var->p.direction + M_PI / 2)) * var->p.move_speed) * 5)
		return (0);
	var->p.p_pos_x -= cosf((var->p.direction + M_PI / 2)) * var->p.move_speed;
	var->p.p_pos_y -= sinf((var->p.direction + M_PI / 2)) * var->p.move_speed;
	return (1);
}
