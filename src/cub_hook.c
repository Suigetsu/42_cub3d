/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:51:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/11 11:08:18 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	up_move(t_cub3d *var)
{
	if (var->map[(int)(var->p.k - 1) / T_SIZE]\
		[(int)(var->p.h / T_SIZE)] == '1')
		return ;
	var->p.p_pos_x -= -cos(var->p.direction) * 8;
	var->p.p_pos_y -= sin(var->p.direction) * 8;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	cast_rays(var);
}

void	down_move(t_cub3d *var)
{
	if (var->map[(int)(var->p.k + 1) / T_SIZE]\
		[(int)(var->p.h / T_SIZE)] == '1')
		return ;
	var->p.p_pos_x += -cos(var->p.direction) * 8;
	var->p.p_pos_y += sin(var->p.direction) * 8;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	cast_rays(var);
}

void	right_move(t_cub3d *var)
{
	if (var->map[(int)round(var->p.p_pos_y / T_SIZE)][(int)round((var->p.p_pos_x + 1) / T_SIZE)] == '1')
			return ;
		var->p.p_pos_x += -cos(var->p.direction * (PI / 2)) * 8;
		var->p.p_pos_y += sin(var->p.direction * (PI / 2)) * 8;
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		cast_rays(var);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *var;
	
	var = (t_cub3d *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		up_move(var);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		down_move(var);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		right_move(var);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		if (var->map[(int)round(var->p.p_pos_y / T_SIZE)][(int)round((var->p.p_pos_x - 1) / T_SIZE)] == '1')
			return ;
		var->p.p_pos_x -= 2;
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		cast_rays(var);
	}
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
        rotate_player(var, ROT_ANGLE * RADIANS, MLX_KEY_RIGHT);
    else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
        rotate_player(var, ROT_ANGLE * RADIANS, MLX_KEY_LEFT);
}
