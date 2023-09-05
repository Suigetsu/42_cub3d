/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:03:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/05 20:29:31 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixels(int x, int y, int color, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			mlx_put_pixel(img, (y * 32) + i, (x * 32) + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player_pixels(int x, int y, int color, mlx_image_t *img)
{
	int	i;
	int	j;
	int	r;

	r = 10;
	i = r * -1;
	while (i <= r)
	{
		j = round(sqrt(r * r - (i * i)));
		mlx_put_pixel(img, (y * 32) + i, (x * 32) + j, color);
		mlx_put_pixel(img, (y * 32) + i, (x * 32) - j, color);
		i++;
	}
}

void	draw_minimap(t_cub3d *var, mlx_image_t *img)
{
	while (var->map[var->y])
	{
		var->x = 0;
		while (var->map[var->y][var->x])
		{
			if (var->map[var->y][var->x] == '1')
				draw_pixels(var->y, var->x, 0x445FFFFF, img);
			else if (var->map[var->y][var->x] == '0')
				draw_pixels(var->y, var->x, 0xFFFFFFFF, img);
			else if (var->map[var->y][var->x] == ' ')
				draw_pixels(var->y, var->x, 0x00000000, img);
			else
				draw_player_pixels(var->y, var->x, 0xF5310446, img);
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
