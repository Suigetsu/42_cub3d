/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:51:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/11 11:38:23 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	up_move(t_cub3d *var)
{
	if (var->map[(int)(var->p.k - 1) / T_SIZE]\
		[(int)(var->p.h / T_SIZE)] == '1')
		return ;
	var->p.p_pos_x -= -cos(var->p.direction) * 3;
	var->p.p_pos_y -= sin(var->p.direction) * 3;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	cast_rays(var);
}

void	down_move(t_cub3d *var)
{
	if (var->map[(int)(var->p.k + 1) / T_SIZE]\
		[(int)(var->p.h / T_SIZE)] == '1')
		return ;
	var->p.p_pos_x += -cos(var->p.direction) * 3;
	var->p.p_pos_y += sin(var->p.direction) * 3;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	cast_rays(var);
}

void	right_move(t_cub3d *var)
{
	if (var->map[(int)round(var->p.p_pos_y / T_SIZE)][(int)round((var->p.p_pos_x + 1) / T_SIZE)] == '1')
			return ;
		var->p.p_pos_x += -cos(var->p.direction * (PI / 2)) * 3;
		var->p.p_pos_y += sin(var->p.direction * (PI / 2)) * 3;
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		cast_rays(var);
}

void	left_move(t_cub3d *var)
{
	if (var->map[(int)round(var->p.p_pos_y / T_SIZE)][(int)round((var->p.p_pos_x - 1) / T_SIZE)] == '1')
			return ;
		var->p.p_pos_x -= -cos(var->p.direction * (PI / 2)) * 3;
		var->p.p_pos_y -= sin(var->p.direction * (PI / 2)) * 3;
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		cast_rays(var);
}

void	keyhook(void *param)
{
	t_cub3d *var;
	
	var = (t_cub3d *)param;
	if (mlx_is_key_down(var->mlx, MLX_KEY_ESCAPE))
		exit(0);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_W))
		up_move(var);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_S))
		down_move(var);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_D))
		right_move(var);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_A))
		left_move(var);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_RIGHT))
		rotate_player(var, ROT_ANGLE * RADIANS, MLX_KEY_RIGHT);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_LEFT))
		rotate_player(var, ROT_ANGLE * RADIANS, MLX_KEY_LEFT);
}
