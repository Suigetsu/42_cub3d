/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bottons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:25:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/24 10:01:11 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_wall(t_cub *var, float x, float y)
{
	if (y / T_SIZE < 0 || x / T_SIZE < 0 || y / T_SIZE > var->y_max - 1 \
		|| x / T_SIZE > var->x_max - 1)
		return (true);
	if (var->map[(int)(y / T_SIZE)][(int)(x / T_SIZE)] == '1')
		return (true);
	return (false);
}

int	up_move(t_cub *var)
{
	if (check_wall(var, var->p.x + cosf(var->p.direction) * \
		var->p.move_speed, var->p.y + sinf(var->p.direction) \
		* var->p.move_speed))
		return (0);
	// printf("%f\n", var->p.direction);
	var->p.p_pos_x += cosf(var->p.direction) * var->p.move_speed;
	var->p.p_pos_y += sinf(var->p.direction) * var->p.move_speed;
	return (1);
}

int	down_move(t_cub *var)
{
	if (check_wall(var, var->p.x - cosf(var->p.direction) * \
		var->p.move_speed, var->p.y - sinf(var->p.direction) \
		* var->p.move_speed))
		return (0);
	var->p.p_pos_x -= cosf(var->p.direction) * var->p.move_speed;
	var->p.p_pos_y -= sinf(var->p.direction) * var->p.move_speed;
	return (1);
}

int	right_move(t_cub *var)
{
	if (check_wall(var, var->p.x + cosf((var->p.direction + M_PI / 2)) * \
		var->p.move_speed, var->p.y + sinf((var->p.direction + M_PI / 2)) \
		* var->p.move_speed))
		return (0);
	var->p.p_pos_x += cosf((var->p.direction + M_PI / 2)) * var->p.move_speed;
	var->p.p_pos_y += sinf((var->p.direction + M_PI / 2)) * var->p.move_speed;
	return (1);
}

int	left_move(t_cub *var)
{
	if (check_wall(var, var->p.x - cosf((var->p.direction + M_PI / 2)) * \
		var->p.move_speed, var->p.y - sinf((var->p.direction + M_PI / 2)) \
		* var->p.move_speed))
		return (0);
	var->p.p_pos_x -= cosf((var->p.direction + M_PI / 2)) * var->p.move_speed;
	var->p.p_pos_y -= sinf((var->p.direction + M_PI / 2)) * var->p.move_speed;
	return (1);
}

int	rotation_move(t_cub *var, int flag)
{
	if (flag == 1)
		var->p.direction += var->p.rot_speed;
	else
		var->p.direction -= var->p.rot_speed;
	return (1);
}

void	keyhook(void *param)
{
	t_cub	*var;

	var = (t_cub *)param;
	var->i = 0;
	if (mlx_is_key_down(var->mlx, MLX_KEY_ESCAPE))
	{
		free_phase1(var);
		exit(0);
	}
	if (mlx_is_key_down(var->mlx, MLX_KEY_W))
		var->i = up_move(var);
	if (mlx_is_key_down(var->mlx, MLX_KEY_S))
		var->i = down_move(var);
	if (mlx_is_key_down(var->mlx, MLX_KEY_D))
		var->i = right_move(var);
	if (mlx_is_key_down(var->mlx, MLX_KEY_A))
		var->i = left_move(var);
	if (mlx_is_key_down(var->mlx, MLX_KEY_RIGHT))
		var->i = rotation_move(var, 1);
	if (mlx_is_key_down(var->mlx, MLX_KEY_LEFT))
		var->i = rotation_move(var, 0);
	if (var->i)
	{
		fix_any_angle(&var->p.direction);
		draw_player_pixels(var, 0xFF378446, var->img);
		init_window(var);
		cast_rays(var);
		draw_minimap(var , var->img );
		var->i = 0;
	}
}
