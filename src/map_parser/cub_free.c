/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:07:50 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/24 10:00:05 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_for_map(t_cub *var)
{
	// if (var->split)
	// 	free_double_ptr(var->split);
	if (var->map)
		free_double_ptr(var->map);
	if (var->line)
		free(var->line);
	if (var->scene)
		free(var->scene);
}

void	free_phase1(t_cub *var, int status)
{
	(void)status;
	if (var->scene)
		free (var->scene);
	if (var->north)
		free_double_ptr(var->north);
	if (var->south)
		free_double_ptr(var->south);
	if (var->east)
		free_double_ptr(var->east);
	if (var->west)
		free_double_ptr(var->west);
	if (var->map)
		free_double_ptr(var->map);
	if (var->floor)
		free_double_ptr(var->floor);
	if (var->ceiling)
		free_double_ptr(var->ceiling);
	if (var->split)
		free_double_ptr(var->split);
}

void	free_for_exit(t_cub *var, int exit_status)
{
	// if (var->ceiling)
	// 	free_double_ptr(var->ceiling);
	// if (var->floor)
	// 	free_double_ptr(var->floor);
	// if (var->north)
	// 	free_double_ptr(var->north);
	// if (var->south)
	// 	free_double_ptr(var->south);
	// if (var->west)
	// 	free_double_ptr(var->west);
	// if (var->east)
	// 	free_double_ptr(var->east);
	// if (var->split)
	// 	free_double_ptr(var->split);
	// if (var->map)
	// 	free_double_ptr(var->map);
	if (var->line)
		free(var->line);
	if (var->scene)
		free(var->scene);
	if (exit_status)
		printf("The map you assigned is probably not valid.\n");
	exit (exit_status);
}
