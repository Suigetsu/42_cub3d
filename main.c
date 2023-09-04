/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:21:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/04 11:59:24 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	img = mlx_new_image(mlx, 200, 200);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	// free_for_exit(&var, 0);
	return (0);
}
