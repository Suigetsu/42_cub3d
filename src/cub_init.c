/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:03:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/09 12:45:08 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	run_mlx(t_cub3d *var)
{
	int			color;

	var->x = 0;
	var->y = 0;
	color = 0;
	var->mlx = mlx_init(var->x_max * T_SIZE, var->y_max * T_SIZE, "test", false);
	var->img = mlx_new_image(var->mlx, var->x_max * T_SIZE, var->y_max * T_SIZE);
	mlx_image_to_window(var->mlx, var->img, 0, 0);
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	cast_rays(var);
	// draw_line(var->img, var, 0x00000000);
	mlx_key_hook(var->mlx, &keyhook, var);
	mlx_loop(var->mlx);
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
