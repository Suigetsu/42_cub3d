/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:03:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/06 17:51:39 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixels2(float x, float y, int color, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < T_SIZE/2)
	{
		j = 0;
		while (j < T_SIZE/2)
		{
			mlx_put_pixel(img, (x * T_SIZE/2) + i, (y * T_SIZE/2) + j, color);
			j++;
		}
		i++;
	}
}

void	draw_pixels(float x, float y, int color, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < T_SIZE)
	{
		j = 0;
		while (j < T_SIZE)
		{
			mlx_put_pixel(img, (x * T_SIZE) + i, (y * T_SIZE) + j, color);
			j++;
		}
		i++;
	}
}

// void	draw_player_pixels(float x, float y, int color, mlx_image_t *img)
// {
// 	double r = 10;
//     double angle, x1, y1;

//     for (int i = 0; i < 360; i++)
//     {
//         angle = i;
//         x1 = r * cos(angle * PI / 180);
//         y1 = r * sin(angle * PI / 180);
// 		int px = x + (int)x1;
//         int py = y + (int)y1;

// 		 for (int j = -x1; j <= x1; j++)
// 		 {
//         	if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT)
//         	{
//             	mlx_put_pixel(img, px * 10, py * 10, color);
//         	}
// 		 }
//         // for (int j = -x1; j <= x1; j++)
//         // {
//         //     mlx_put_pixel(img, (x + (int) x1) * T_SIZE, (y + (int)y1) * T_SIZE, color);
//         // }
//     }
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
				draw_pixels2(var->p.p_pos_x, var->p.p_pos_y, 0x56F52A23, img);
				// mlx_put_pixel(img, var->p.p_pos_x, var->p.p_pos_y, 0x56F52A23);
				// draw_player_pixels(var->p.p_pos_x, var->p.p_pos_y, 0xFF378446, img);
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
	mlx = mlx_init(var->x_max * T_SIZE, var->y_max * T_SIZE, "test", false);
	img = mlx_new_image(mlx, var->x_max * T_SIZE, var->y_max * T_SIZE);
	mlx_image_to_window(mlx, img, 0, 0);
	draw_minimap(var, img);
	// draw_line(var, img);
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
