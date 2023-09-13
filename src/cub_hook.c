/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:51:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/13 19:16:04 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	up_move(t_cub3d *var)
{
	if ((int)((var->p.k - 1) / T_SIZE) == 0 || \
		(int)((var->p.h + 1) / T_SIZE) == var->x_max - 1 || \
		(int)((var->p.h - 1) / T_SIZE) == 0)
		return ;
	var->p.p_pos_x -= sinf(var->p.direction) * 3;
	var->p.p_pos_y -= cosf(var->p.direction) * 3;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	// cast_rays(var);
}

void	down_move(t_cub3d *var)
{
	if ((int)((var->p.k + 1) / T_SIZE) == var->y_max - 1 || \
		(int)((var->p.h + 1) / T_SIZE) == var->x_max - 1 || \
		(int)((var->p.h - 1) / T_SIZE) == 0)
		return ;
	var->p.p_pos_x += sinf(var->p.direction) * 3;
	var->p.p_pos_y += cosf(var->p.direction) * 3;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	// cast_rays(var);
}

void	right_move(t_cub3d *var)
{
	if ((int)((var->p.k - 1) / T_SIZE) == 0 || \
		(int)((var->p.k + 1) / T_SIZE) == var->y_max - 1 || \
		(int)((var->p.h + 1) / T_SIZE) == var->x_max - 1 || \
		(int)((var->p.h - 1) / T_SIZE) == 0)
		return ;
	var->p.p_pos_x += cosf(var->p.direction) * 3;
	var->p.p_pos_y -= sinf(var->p.direction) * 3;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	// cast_rays(var);
}

void	left_move(t_cub3d *var)
{
	if ((int)((var->p.k - 1) / T_SIZE) == 0 || \
		(int)((var->p.k + 1) / T_SIZE) == var->y_max - 1 || \
		(int)((var->p.h + 1) / T_SIZE) == var->x_max - 1 || \
		(int)((var->p.h - 1) / T_SIZE) == 0)
		return ;
	var->p.p_pos_x -= cosf(var->p.direction) * 3;
	var->p.p_pos_y += sinf(var->p.direction) * 3;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	// cast_rays(var);
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
