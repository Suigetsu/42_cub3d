/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:43:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/22 12:06:29 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixels(float x, float y, int color, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < T_SIZE * MINIMAP_SF)
	{
		j = 0;
		while (j < T_SIZE * MINIMAP_SF)
		{
			// if ( j == T_SIZE -1 && i == T_SIZE-1 )
				mlx_put_pixel(img, (x * T_SIZE * MINIMAP_SF) + i, (y * T_SIZE * MINIMAP_SF) + j, color);
			if (j == (T_SIZE - 1) * MINIMAP_SF)
				mlx_put_pixel(img, (x * T_SIZE * MINIMAP_SF) + i, (y * T_SIZE * MINIMAP_SF) + j, 0);
			if (i == (T_SIZE - 1) * MINIMAP_SF)
				mlx_put_pixel(img, (x * T_SIZE * MINIMAP_SF) + i, (y * T_SIZE * MINIMAP_SF) + j, 0);
			j++;
		}
		i++;
	}
}

void	draw_player_pixels(t_cub *var, int color, mlx_image_t *img)
{
	float	i;
	float	j;

	i = var->p.p_pos_y;
	j = var->p.p_pos_x;
	var->p.x = (var->p.p_pos_x + (T_SIZE / 2));
	var->p.y = (var->p.p_pos_y + (T_SIZE / 2));
	while (i < var->p.p_pos_y + T_SIZE)
	{
		j = var->p.p_pos_x;
		while (j < var->p.p_pos_x + T_SIZE)
		{
			if (pow(j - var->p.x, 2) + \
				pow(i - var->p.y, 2) <= pow(var->p.radius, 2))
				mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
	// draw_line(var, var->img);
}

void	draw_minimap(t_cub *var, mlx_image_t *img)
{
	var->y = 0;
	while (var->map[(int)var->y])
	{
		var->x = 0;
		while (var->map[(int)var->y][(int)var->x])
		{
			if (var->map[(int)var->y][(int)var->x] == '1')
				draw_pixels(var->x, var->y, ft_pixel(100,149,237,255), img);
			else if (var->map[(int)var->y][(int)var->x] == ' ')
				draw_pixels(var->x, var->y, ft_pixel(0,0,0,255), img);
			else
				draw_pixels(var->x, var->y, ft_pixel(255,255,255,255), img);
			var->x++;
		}
		var->y++;
	}
	// printf("%f - %f - %f\n", var->y, var->x, MINIMAP_SF);
}
