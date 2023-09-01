/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:21:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/01 13:40:26 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	var;

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
}
