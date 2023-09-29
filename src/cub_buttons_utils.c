/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_buttons_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:04:48 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/29 12:57:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rotation_move(t_cub *var, int flag)
{
	if (flag == 1)
		var->p.direction += var->p.rot_speed;
	else
		var->p.direction -= var->p.rot_speed;
	return (1);
}

void	mouse_rotation(t_cub *var)
{
	mlx_set_cursor_mode(var->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(var->mlx, &var->mouse_x, &var->mouse_y);
	if (var->mouse_x < var->mouse_pos)
	{
		var->mouse_pos = var->mouse_x;
		var->i = rotation_move(var, 0);
	}
	else if (var->mouse_x > var->mouse_pos)
	{
		var->mouse_pos = var->mouse_x;
		var->i = rotation_move(var, 1);
	}
	if (var->mouse_x > WIDTH || var->mouse_x < 0 || \
		var->mouse_y > HEIGHT || var->mouse_y < 0)
	{
		var->mouse_pos = WIDTH / 2;
		mlx_set_mouse_pos(var->mlx, var->mouse_pos, HEIGHT / 2);
	}
}

void	update_player(t_cub *var)
{
	var->p.x = (var->p.p_pos_x + (T_SIZE / 2));
	var->p.y = (var->p.p_pos_y + (T_SIZE / 2));
	fix_any_angle(&var->p.direction);
	init_window(var);
	cast_rays(var);
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
}

void	keyhook(void *param)
{
	t_cub	*var;
	int		i;

	i = 0;
	var = (t_cub *)param;
	mouse_rotation(var);
	if (mlx_is_key_down(var->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(var->mlx);
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
		update_player(var);
	var->i = 0;
}
