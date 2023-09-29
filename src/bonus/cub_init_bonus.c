/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:03:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/29 20:24:17 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_window(t_cub *var)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT / 2)
			mlx_put_pixel(var->img, i, j, \
				ft_pixel(var->c_r, var->c_g, var->c_b, 255));
	}
	i = -1;
	while (++i < WIDTH)
	{
		j = (HEIGHT / 2) - 1;
		while (++j < HEIGHT)
			mlx_put_pixel(var->img, i, j, \
				ft_pixel(var->f_r, var->f_g, var->f_b, 255));
	}
}

int	run_mlx(t_cub *var)
{
	int	color;

	var->p.x = (var->p.p_pos_x + (T_SIZE / 2));
	var->p.y = (var->p.p_pos_y + (T_SIZE / 2));
	color = 0;
	var->mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(var->mlx, var->img, 0, 0);
	init_window(var);
	if (get_tex(var))
	{
		mlx_close_window(var->mlx);
		return (ERROR);
	}
	cast_rays(var);
	draw_minimap(var, var->img);
	draw_player_pixels(var, 0xFF378446, var->img);
	mlx_loop_hook(var->mlx, &keyhook, var);
	mlx_loop_hook(var->mlx, &update_player, var);
	mlx_loop(var->mlx);
	return (0);
}

void	init_variables(t_cub *var)
{
	var->p.radius = 3.0;
	var->x_max *= T_SIZE;
	var->y_max *= T_SIZE;
	var->p.radians = (M_PI / 180);
	var->p.fov = 60 * var->p.radians;
	var->p.rot_speed = 0.05;
	var->p.move_speed = 7.0;
	var->p.rotation_angle = (float)(M_PI / 2);
	get_direction(var);
}

int	init_vars(t_cub *var, int ac, char **av)
{
	ft_bzero(var, sizeof(t_cub));
	if (ac != 2)
		exit(printf("Error\nWrong number of arguments\n"));
	if (check_filename(av[1]))
		exit(printf("Error\nInvalid map extension\n"));
	if (read_map(av[1], var))
		exit(printf("Error\nThe map you assigned is probably not valid.\n"));
	if (parse_info(var))
		return (free_phase1(var), \
		printf("Error\nThe map you assigned is probably not valid.\n"));
	if (check_map(av[1], var))
		return (free_phase1(var), \
		printf("Error\nThe map you assigned is probably not valid.\n"));
	if (is_map_valid(var))
		return (free_phase1(var), \
		printf("Error\nThe map you assigned is probably not valid.\n"));
	init_variables(var);
	return (0);
}
