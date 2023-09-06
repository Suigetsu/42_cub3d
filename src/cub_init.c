/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:03:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/06 15:34:47 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixels(int x, int y, int color, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < TILESIZE)
	{
		j = 0;
		while (j < TILESIZE)
		{
			mlx_put_pixel(img, (x * TILESIZE) + i, (y * TILESIZE) + j, color);
			j++;
		}
		i++;
	}
}

// void	draw_player_pixels(int x, int y, int color, mlx_image_t *img)
// {
// 	// double pi = 3.1415926535;
//     // double angle;
    
//     // for (angle = 0; angle < 360; angle += 1) {
//     //     double angle_rad = angle * pi / 180.0;
//     //     double x1 = 0.5 * sin(angle_rad);
//     //     double y1 = 0.5 * cos(angle_rad);

//     //     int pixel_x = (int)((x + x1) * 32);
//     //     int pixel_y = (int)((y + y1) * 32);

//     //     mlx_put_pixel(img, pixel_x, pixel_y, color);
//     // }
// }

void	draw_minimap(t_cub3d *var, mlx_image_t *img)
{
	while (var->map[(int)var->y])
	{
		var->x = 0;
		while (var->map[(int)var->y][(int)var->x])
		{
			if (var->map[(int)var->y][(int)var->x] == '1')
				draw_pixels(var->x, var->y, 0x445FFFFF, img);
			else if (var->map[(int)var->y][(int)var->x] == '0')
				draw_pixels(var->x, var->y, 0xFFFFFFFF, img);
			else if (var->map[(int)var->y][(int)var->x] == ' ')
				draw_pixels(var->x, var->y, 0x00000000, img);
			else
			{
				draw_pixels(var->x, var->y, 0xFFFFFFFF, img);
				// draw_player_pixels(var->p.p_pos_y, var->p.p_pos_x, 0xF5310446, img);
			}
			var->x++;
		}
		var->y++;
	}
}

int	run_mlx(t_cub3d *var)
{
	mlx_t		*mlx;
	mlx_image_t *img;
	int			color;

	var->x = 0;
	var->y = 0;
	color = 0;
	mlx = mlx_init(var->x_max * 32, var->y_max * 32, "test", false);
	img = mlx_new_image(mlx, var->x_max * 32, var->y_max * 32);
	mlx_image_to_window(mlx, img, 0, 0);
	draw_minimap(var, img);
	mlx_key_hook(mlx, &keyhook, var);
	mlx_loop(mlx);
	return (0);
}

void	init_vars(t_cub3d *var, int ac, char **av)
{
	ft_bzero(var, sizeof(t_cub3d));
	if (ac != 2)
	{
		printf("Wrong number of arguments\n");
		exit (1);
	}
	if (check_filename(av[1]))
	{
		printf("Invalid map extension\n");
		exit (1);
	}
	if (read_map(av[1], var))
		free_for_exit(var, 1);
	if (parse_info(var))
		free_for_exit(var, 1);
	free_for_map(var);
	if (check_map(av[1], var))
		free_for_exit(var, 1);
	if (is_map_valid(var))
		free_for_exit(var, 1);
}
