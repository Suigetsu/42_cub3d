/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:03:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/24 10:01:21 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void init_window(t_cub *var)
{
	int i;
	int j;

	i = 0;
	while (i < var->x_max)
	{
		j = 0;
		while (j < var->y_max / 2)
		{
			mlx_put_pixel(var->img, i , j, ft_pixel(135,206,250, 255));
			j++;
		}
		i++;
	}
	i = 0;
	while (i < var->x_max)
	{
		j = var->y_max / 2;
		while (j < var->y_max)
		{
			mlx_put_pixel(var->img, i , j, ft_pixel(192,192,192, 255));
			j++;
		}
		i++;
	}
}
int	run_mlx(t_cub *var)
{
	int			color;

	var->x = 0;
	var->y = 0;
	color = 0;
	var->mlx = mlx_init(var->x_max, var->y_max, "test", false);
	var->img = mlx_new_image(var->mlx, var->x_max, var->y_max);
	mlx_image_to_window(var->mlx, var->img, 0, 0);
	draw_player_pixels(var, 0xFF378446, var->img);
	init_window(var);
	cast_rays(var);
	draw_minimap(var , var->img);
	// draw_3d_projection(var);
	mlx_loop_hook(var->mlx, &keyhook, var);
	mlx_loop(var->mlx);
	return (0);
}

void	init_variables(t_cub *var)
{
	var->p.radius = 3;
	var->x_max *= T_SIZE;
	var->y_max *= T_SIZE;
	var->p.radians = M_PI / 180;
	var->p.fov = 60 * var->p.radians;
	var->p.rot_speed = 0.07;
	var->p.move_speed = 5;
	var->p.rotation_angle = M_PI / 2;
	get_direction(var);
}

void	collect_paths(t_cub *var)
{
	var->paths[0] = var->north[1];
	var->paths[1] = var->south[1];
	var->paths[2] = var->west[1];
	var->paths[3] = var->east[1];
}

int	init_vars(t_cub *var, int ac, char **av)
{
	ft_bzero(var, sizeof(t_cub));
	if (ac != 2)
		exit(printf("Wrong number of arguments\n"));
	if (check_filename(av[1]))
		exit(printf("Invalid map extension\n"));
	if (read_map(av[1], var))
		exit(printf("The map you assigned is probably not valid.\n"));
	if (parse_info(var))
		return (free_phase1(var), 1);
	if (check_map(av[1], var))
		return (free_phase1(var), 1);
	if (is_map_valid(var))
		return (free_phase1(var), 1);
	collect_paths(var);
	get_tex(var);
	// get_images(path);
	// var->txt = mlx_load_png(var->north[1]);
	// if (!var->txt)
	// {
	// 	printf("can't open file\n");
	// 	exit(1);
	// }
	init_variables(var);
	return (0);
}
