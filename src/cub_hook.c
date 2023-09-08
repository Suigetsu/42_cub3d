/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:51:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/08 11:51:26 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *var;
	var = (t_cub3d *)param;
	// printf("hello %f\n", var->p.p_pos_x);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		printf("up\n");
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		printf("down\n");
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		printf("right\n");
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		printf("left\n");
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
    {
        // printf("rotate right\n");
        rotate_player(var, 30); 
        // mlx_destroy_image(var->img);
		// mlx_delete_image(var->mlx, var->img);
		// var->img = mlx_new_image(var->mlx, var->x_max * T_SIZE, var->y_max * T_SIZE);
		// mlx_image_to_window(var->mlx, var->img, 0, 0);
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
        draw_line(var->img, var, 0x00000000); 
    }
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
    {
        // printf("rotate left\n");
        rotate_player(var, -30);
        // mlx_destroy_image(var->img);
		// mlx_delete_image(var->mlx, var->img);
		// mlx_image_to_window(var->mlx, var->img, 0, 0);
		// draw_minimap(var, var->img);
		// mlx_delete_image(var->mlx, var->img);
		// var->img = mlx_new_image(var->mlx, var->x_max * T_SIZE, var->y_max * T_SIZE);
		// mlx_image_to_window(var->mlx, var->img, 0, 0);
		draw_minimap(var, var->img);
		draw_player_pixels(var, 0xFF378446, var->img);
        draw_line(var->img, var, 0x00000000);
    }
	// else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	// 	printf("rotate right\n");
	// else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	// 	printf("rotate left\n");
}
