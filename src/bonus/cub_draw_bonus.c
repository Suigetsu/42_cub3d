/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:43:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/30 16:48:46 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

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
			mlx_put_pixel(img, (x * T_SIZE * MINIMAP_SF) + i, \
				(y * T_SIZE * MINIMAP_SF) + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player_pixels(t_cub *var, int color, mlx_image_t *img)
{
	float	i;
	float	j;

	i = var->p.p_pos_y * MINIMAP_SF;
	j = var->p.p_pos_x * MINIMAP_SF;
	if (var->y_max / T_SIZE > 50 || var->x_max / T_SIZE > 50)
		return ;
	var->minix = ((var->p.p_pos_x * MINIMAP_SF) + ((T_SIZE * MINIMAP_SF) / 2));
	var->miniy = ((var->p.p_pos_y * MINIMAP_SF) + ((T_SIZE * MINIMAP_SF) / 2));
	while (i < (var->p.p_pos_y * MINIMAP_SF) + (T_SIZE * MINIMAP_SF))
	{
		j = (var->p.p_pos_x * MINIMAP_SF);
		while (j < (var->p.p_pos_x * MINIMAP_SF) + (T_SIZE * MINIMAP_SF))
		{
			if (pow(j - var->minix, 2) + \
				pow(i - var->miniy, 2) <= pow(var->p.radius, 2))
				mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_cub *var, mlx_image_t *img)
{
	var->y = 0;
	if (var->y_max / T_SIZE > 50 || var->x_max / T_SIZE > 50)
	{
		printf("The map is too big to be shown, but it's there 👀\n");
		return ;
	}
	while (var->map[(int)var->y])
	{
		var->x = 0;
		while (var->map[(int)var->y][(int)var->x])
		{
			if (var->map[(int)var->y][(int)var->x] == '1')
				draw_pixels(var->x, var->y, ft_pixel(139, 145, 151, 255), img);
			else if (var->map[(int)var->y][(int)var->x] == '0' || \
				var->map[(int)var->y][(int)var->x] == var->p.dir)
				draw_pixels(var->x, var->y, ft_pixel(255, 255, 255, 255), img);
			var->x++;
		}
		var->y++;
	}
}

void	draw_textures(t_cub *var)
{
	if (var->ray.inter_axis == 1 && facing_up_down(var) == 1)
	{
		var->x_step = (var->txt[0]->width / T_SIZE) * \
		fmod(var->ray.inter_x, T_SIZE);
		var->intxt = 0;
	}
	else if (var->ray.inter_axis == 1 && !facing_up_down(var))
	{
		var->x_step = (var->txt[1]->width / T_SIZE) * \
		fmod(var->ray.inter_x, T_SIZE);
		var->intxt = 1;
	}
	else if (!var->ray.inter_axis && facing_right_left(var) == 1)
	{
		var->x_step = (var->txt[2]->width / T_SIZE) * \
		fmod(var->ray.inter_y, T_SIZE);
		var->intxt = 2;
	}
	else if (!var->ray.inter_axis && !facing_right_left(var))
	{
		var->x_step = (var->txt[3]->width / T_SIZE) * \
		fmod(var->ray.inter_y, T_SIZE);
		var->intxt = 3;
	}
}
