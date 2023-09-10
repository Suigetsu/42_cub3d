/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:51:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/10 11:46:40 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	up_move(t_cub3d *var)
{
	if (var->map[(int)(var->p.p_pos_y - 1) / T_SIZE]\
		[(int)(var->p.p_pos_x / T_SIZE)] == '1')
		return ;
	
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *var;
	
	var = (t_cub3d *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		printf("%f\n", var->p.p_pos_y/T_SIZE);
		up_move(var);
		// if (var->map[(int)(var->p.p_pos_y - 1) / T_SIZE][(int)(var->p.p_pos_x / T_SIZE)] == '1')
		// 	return ;
		// var->p.p_pos_x -= cos(var->p.direction) * 3;
		// var->p.p_pos_y -= sin(var->p.direction) * 3;
		// draw_minimap(var, var->img);
		// draw_player_pixels(var, 0xFF378446, var->img);
		// cast_rays(var);
        // draw_line(var->img, var, 0x00000000); 
	}
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		// var->p.p_pos_x += cos(var->p.direction) * 5;
		// var->p.p_pos_y += sin(var->p.direction) * 5;
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		cast_rays(var);
        // draw_line(var->img, var, 0x00000000); 
	}
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		// var->p.p_pos_x += cos(var->p.direction) * 5;
		// draw_minimap(var, var->img);
		// draw_player_pixels(var, 0xFF378446, var->img);
		// cast_rays(var);
        // draw_line(var->img, var, 0x00000000); 
	}
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		// if (var->map[(int)round(var->p.p_pos_y / T_SIZE)][(int)round((var->p.p_pos_x - 1) / T_SIZE)] == '1')
		// 	return ;
		// var->p.p_pos_x -= 2;
		// draw_minimap(var, var->img);
		// draw_player_pixels(var, 0xFF378446, var->img);
		// cast_rays(var);
        // draw_line(var->img, var, 0x00000000); 
	}
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
    {
        rotate_player(var, - ROT_ANGLE * RADIANS); 
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		cast_rays(var);
        // draw_line(var->img, var, 0x00000000); 
    }
    else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
    {
        rotate_player(var, ROT_ANGLE * RADIANS);
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
		cast_rays(var);
        // draw_line(var->img, var, 0x00000000);
    }
}
