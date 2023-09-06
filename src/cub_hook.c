/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:51:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/06 15:21:59 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *var;
	var = (t_cub3d *)param;
	printf("hello %f\n", var->p.p_pos_x);
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
		printf("rotate right\n");
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		printf("rotate left\n");
}
