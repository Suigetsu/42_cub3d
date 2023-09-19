/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:51:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/19 16:58:02 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_wall(t_cub3d *var, float x, float y)
{
	if (y / T_SIZE < 0 || x / T_SIZE < 0 || y / T_SIZE > var->y_max - 1 \
		|| x / T_SIZE > var->x_max - 1)
		return (true);
	if (var->map[(int)(y / T_SIZE)][(int)(x / T_SIZE)] == '1')
		return (true);
	return (false);
}

void	up_move(t_cub3d *var)
{
	if (check_wall(var, var->p.h + cosf(var->p.direction * RADIANS) * MOVE_SPEED, \
		var->p.k + sinf(var->p.direction * RADIANS) * MOVE_SPEED))
		return ;
	var->p.p_pos_x += cosf(var->p.direction * RADIANS) * MOVE_SPEED;
	var->p.p_pos_y += sinf(var->p.direction * RADIANS) * MOVE_SPEED;
	// draw_minimap(var, var->img);
	// draw_player_pixels(var, 0xFF378446, var->img);
	// cast_rays(var, var->img);
	// draw_line(var->img, var, 0xFFFFFD);
}

void	down_move(t_cub3d *var)
{
	if (check_wall(var, var->p.h - cosf(var->p.direction * RADIANS) * MOVE_SPEED, \
		var->p.k - sinf(var->p.direction * RADIANS) * MOVE_SPEED))
		return ;
	var->p.p_pos_x -= cosf(var->p.direction * RADIANS) * MOVE_SPEED;
	var->p.p_pos_y -= sinf(var->p.direction * RADIANS) * MOVE_SPEED;
	// draw_minimap(var, var->img);
	// draw_player_pixels(var, 0xFF378446, var->img);
	// cast_rays(var, var->img);
	// draw_line(var->img, var, 0xFFFFFD);
}

void	right_move(t_cub3d *var)
{
	if (check_wall(var, var->p.h - sinf(var->p.direction * RADIANS) * \
		MOVE_SPEED, var->p.k + cosf(var->p.direction * RADIANS) * MOVE_SPEED))
		return ;
	var->p.p_pos_x += cosf((var->p.direction + 90) * RADIANS) * MOVE_SPEED;
	var->p.p_pos_y -= sinf((var->p.direction + 90) * RADIANS) * MOVE_SPEED;
	// draw_minimap(var, var->img);
	// draw_player_pixels(var, 0xFF378446, var->img);
	// cast_rays(var, var->img);
	// draw_line(var->img, var, 0xFFFFFD);
}

void	left_move(t_cub3d *var)
{
	if (check_wall(var, var->p.h + sinf(var->p.direction * RADIANS) * \
		MOVE_SPEED, var->p.k - cosf(var->p.direction * RADIANS) * MOVE_SPEED))
		return ;
	var->p.p_pos_x -= cosf((var->p.direction + 90) * RADIANS) * MOVE_SPEED;
	var->p.p_pos_y += sinf((var->p.direction + 90) * RADIANS) * MOVE_SPEED;
	// draw_minimap(var, var->img);
	// draw_player_pixels(var, 0xFF378446, var->img);
	// cast_rays(var, var->img);
	// draw_line(var->img, var, 0xFFFFFD);
}

void	keyhook(void *param)
{
	t_cub3d *var;
	// int i;
	
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
		fix_any_angle(&var->p.direction);
		// draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		// cast_rays(var, var->img);
		// draw_line(var->img, var, 0xFFFFFD);
	}
	if (mlx_is_key_down(var->mlx, MLX_KEY_LEFT))
	{
		var->p.direction -= ROT_SPEED;
		fix_any_angle(&var->p.direction);
		// draw_minimap(var, var->img);
		// draw_player_pixels(var, 0xFF378446, var->img);
		// cast_rays(var, var->img);
		// draw_line(var->img, var, 0xFFFFFD);
	}
	// cast_rays(var, var->img);
	// if (i == 1)
	// {
	// 	//draw;
	// 	i = 0;
	// }
}
