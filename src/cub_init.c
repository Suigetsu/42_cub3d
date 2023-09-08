/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:03:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/08 12:02:09 by hrahmane         ###   ########.fr       */
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
			if (j == T_SIZE - 1)
				mlx_put_pixel(img, (x * T_SIZE) + i, (y * T_SIZE) + j, 0);
			if (i == T_SIZE - 1)
				mlx_put_pixel(img, (x * T_SIZE) + i, (y * T_SIZE) + j, 0);
			j++;
		}
		i++;
	}
}

bool check_wall(t_cub3d *var, float x, float y)
{
	if (var->map[(int)x][(int)y] == '1')
		return (true);
	return (false);
}

void	draw_player_pixels(t_cub3d *var, int color, mlx_image_t *img)
{
	float	i;
	float	j;

	var->p.radius = 3;
	i = var->p.p_pos_y;
	j = var->p.p_pos_x;
	var->p.h = var->p.p_pos_x + (T_SIZE / 2);
	var->p.k = var->p.p_pos_y + (T_SIZE / 2);
	while (i < var->p.p_pos_y + T_SIZE)
	{
		j = var->p.p_pos_x;
		while (j < var->p.p_pos_x + T_SIZE)
		{
			if (pow(j - var->p.h, 2) + \
				pow(i - var->p.k, 2) <= pow(var->p.radius, 2))
				mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_line(mlx_image_t *img, t_cub3d *var, int color)
{
	float	dx;
	float	dy;
	float	pixelx;
	float	pixely;
	int		pixels;
	
	get_direction(var);
	printf("line direction %f\n", var->p.direction);
	dx = cos(var->p.direction);
	dy = -sin(var->p.direction);
	pixelx = var->p.h;
	pixely = var->p.k;
	pixels = 50;
	while (pixels)
	{
		mlx_put_pixel(img, pixelx, pixely, color);
		pixelx += dx;
		pixely += dy;
		--pixels;
	}
}

void	draw_minimap(t_cub3d *var, mlx_image_t *img)
{
	var->y = 0;
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
				draw_pixels(var->x, var->y, 0xFFFFFFFF, img);
			// draw_player_pixels(var, 0xFF378446, img);
			// draw_line(img, var, 0x00000000);
			var->x++;
		}
		var->y++;
	}
}


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
	draw_line(var->img, var, 0x00000000);
	// draw_line(var, var->img);
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
