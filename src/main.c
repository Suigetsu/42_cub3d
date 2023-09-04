/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:21:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/04 16:58:11 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d		var;
	mlx_t		*mlx;
	mlx_image_t *img;

	ft_bzero(&var, sizeof(t_cub3d));
	if (ac != 2)
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	if (check_filename(av[1]))
	{
		printf("Invalid map extension\n");
		return (1);
	}
	if (read_map(av[1], &var))
		free_for_exit(&var, 1);
	if (parse_info(&var))
		free_for_exit(&var, 1);
	free_for_map(&var);
	if (check_map(av[1], &var))
		free_for_exit(&var, 1);
	if (is_map_valid(&var))
		free_for_exit(&var, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	int i = 0, j = 0;
	int x = 0, y = 0;
	int color;
	while (var.map[i])
	{
		j = 0;
		while (var.map[i][j])
		{
			if (var.map[i][j] == '1')
				color = 0xFFFFFFFF;
			else if (var.map[i][j] == '0')
				color = 0xFFFFFFFF;
			else if (var.map[i][j] == ' ')
				color = 0x00000000;
			else
				color = 0xF5310446;
			while (x < (i + 1) * 32)
			{
				y = j;
				while (y < (j + 1) * 32)
				{
					mlx_put_pixel(img, x, y, color);
					y++;
				}
				x++;
			}
			j++;
		}
		i++;
	}	
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_loop(mlx);
	// free_for_exit(&var, 0);
	return (0);
}
