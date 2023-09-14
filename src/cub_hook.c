/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:51:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/14 13:09:20 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	up_move(t_cub3d *var)
{
	if ((int)((var->p.k - 1) / T_SIZE) == 0 || \
		(int)((var->p.h + 1) / T_SIZE) == var->x_max - 1 || \
		(int)((var->p.h - 1) / T_SIZE) == 0)
		return ;
	var->p.p_pos_x += cosf(var->p.direction) * MOVE_SPEED;
	var->p.p_pos_y += sinf(var->p.direction) * MOVE_SPEED;
	printf ("%f\n", var->p.direction);
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	// draw_line(var->img, var, 0xFFFFFD);
	cast_rays(var);
}

void	down_move(t_cub3d *var)
{
	if ((int)((var->p.k + 1) / T_SIZE) == var->y_max - 1 || \
		(int)((var->p.h + 1) / T_SIZE) == var->x_max - 1 || \
		(int)((var->p.h - 1) / T_SIZE) == 0)
		return ;
	var->p.p_pos_x -= cosf(var->p.direction) * MOVE_SPEED;
	var->p.p_pos_y -= sinf(var->p.direction) * MOVE_SPEED;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	// draw_line(var->img, var, 0xFFFFFD);
	cast_rays(var);
}

void	right_move(t_cub3d *var)
{
	if ((int)((var->p.k - 1) / T_SIZE) == 0 || \
		(int)((var->p.k + 1) / T_SIZE) == var->y_max - 1 || \
		(int)((var->p.h + 1) / T_SIZE) == var->x_max - 1 || \
		(int)((var->p.h - 1) / T_SIZE) == 0)
		return ;
	var->p.p_pos_x -= cosf(var->p.direction - ROT_ANGLE) * MOVE_SPEED;
	var->p.p_pos_y -= sinf(var->p.direction - ROT_ANGLE) * MOVE_SPEED;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	// draw_line(var->img, var, 0xFFFFFD);
	cast_rays(var);
}

void	left_move(t_cub3d *var)
{
	if ((int)((var->p.k - 1) / T_SIZE) == 0 || \
		(int)((var->p.k + 1) / T_SIZE) == var->y_max - 1 || \
		(int)((var->p.h + 1) / T_SIZE) == var->x_max - 1 || \
		(int)((var->p.h - 1) / T_SIZE) == 0)
		return ;
	var->p.p_pos_x -= cosf(var->p.direction + ROT_ANGLE) * MOVE_SPEED;
	var->p.p_pos_y -= sinf(var->p.direction + ROT_ANGLE) * MOVE_SPEED;
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	// draw_line(var->img, var, 0xFFFFFD);
	cast_rays(var);
}

void	keyhook(void *param)
{
	t_cub3d *var;
	
	var = (t_cub3d *)param;
	if (mlx_is_key_down(var->mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(var->mlx, MLX_KEY_W))
		up_move(var);
	if (mlx_is_key_down(var->mlx, MLX_KEY_S))
		down_move(var);
	if (mlx_is_key_down(var->mlx, MLX_KEY_D))
		right_move(var);
	if (mlx_is_key_down(var->mlx, MLX_KEY_A))
		left_move(var);
	if (mlx_is_key_down(var->mlx, MLX_KEY_RIGHT))
	{
		var->p.direction += ROT_SPEED;
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		// draw_line(var->img, var, 0xFFFFFD);
		cast_rays(var);
		//rotate_player(var, ROT_SPEED, MLX_KEY_RIGHT);
	}
	if (mlx_is_key_down(var->mlx, MLX_KEY_LEFT))
	{
		var->p.direction -= ROT_SPEED;
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		// draw_line(var->img, var, 0xFFFFFD);
		cast_rays(var);
		//rotate_player(var, ROT_SPEED, MLX_KEY_LEFT);
	}
}
