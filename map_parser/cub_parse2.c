/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:25:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/02 13:19:48 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	 store_info(char *info_line, t_cub3d *var)
{
	if (ft_strncmp(info_line, "NO ", 3) == 0)
	{
		if (var->north)
			return (ERROR);
		var->north = ft_split(info_line, ' ');
	}
	else if (ft_strncmp(info_line, "SO ", 3) == 0)
	{
		if (var->south)
			return (ERROR);
		var->south = ft_split(info_line, ' ');
	}
	else if (ft_strncmp(info_line, "WE ", 3) == 0)
	{
		if (var->west)
			return (ERROR);
		var->west = ft_split(info_line, ' ');
	}
	else if (ft_strncmp(info_line, "EA ", 3) == 0)
	{
		if (var->east)
			return (ERROR);
		var->east = ft_split(info_line, ' ');
	}
	return (0);
}

int	store_color_info(char *info_line, t_cub3d *var)
{
	if (ft_strncmp(info_line, "F ", 2) == 0)
	{
		if (var->floor)
			return (ERROR);
		var->floor = ft_split(info_line, ' ');
	}
	else if (ft_strncmp(info_line, "C ", 2) == 0)
	{
		if (var->ceiling)
			return (ERROR);
		var->ceiling = ft_split(info_line, ' ');
	}
	return (0);
}

int	split_info(t_cub3d *var)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (store_info(var->map[i], var))
			return (free_double_ptr(var->map), ERROR);
		if (store_color_info(var->map[i], var))
			return (free_double_ptr(var->map), ERROR);
		i++;
	}
	if (var->north[2] || var->south[2] || var->west[2] || var->east[2] || \
		var->floor[2] || var->ceiling[2] || !var->north[1] || \
		!var->south[1] || !var->west[1] || !var->east[1] || !var->floor[1] || \
		!var->ceiling[1])
		return (ERROR);
	if (path_validity(var) || color_validity(var))
		return (ERROR);
	return (0);
}
