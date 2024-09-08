/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:25:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/29 12:11:24 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	skip_space(char *info_line, int path_index, t_cub *var)
{
	int	i;

	i = 2;
	if (path_index != -1)
	{
		if (var->paths[path_index])
			return (ERROR);
	}
	while (info_line[i] && info_line[i] == ' ')
		i++;
	if (!info_line[i])
		return (ERROR);
	return (i);
}

int	store_info(char *line, t_cub *var)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (skip_space(line, 0, var) == ERROR)
			return (ERROR);
		var->paths[0] = ft_strtrim(&line[skip_space(line, 0, var)], " ");
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (skip_space(line, 1, var) == ERROR)
			return (ERROR);
		var->paths[1] = ft_strtrim(&line[skip_space(line, 1, var)], " ");
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (skip_space(line, 2, var) == ERROR)
			return (ERROR);
		var->paths[2] = ft_strtrim(&line[skip_space(line, 2, var)], " ");
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (skip_space(line, 3, var) == ERROR)
			return (ERROR);
		var->paths[3] = ft_strtrim(&line[skip_space(line, 3, var)], " ");
	}
	return (0);
}

int	store_color_info(char *info_line, t_cub *var)
{
	if (ft_strncmp(info_line, "F ", 2) == 0)
	{
		if (var->floor)
			return (ERROR);
		if (skip_space(info_line, -1, var) == ERROR)
			return (ERROR);
		var->floor = malloc(sizeof(char *) * 3);
		var->floor[0] = ft_strdup("F");
		var->floor[1] = ft_strdup(&info_line[skip_space(info_line, -1, var)]);
		var->floor[2] = NULL;
	}
	else if (ft_strncmp(info_line, "C ", 2) == 0)
	{
		if (var->ceiling)
			return (ERROR);
		if (skip_space(info_line, -1, var) == ERROR)
			return (ERROR);
		var->ceiling = malloc(sizeof(char *) * 3);
		var->ceiling[0] = ft_strdup("C");
		var->ceiling[1] = ft_strdup(&info_line[skip_space(info_line, -1, var)]);
		var->ceiling[2] = NULL;
	}
	return (0);
}

int	textures_extension(t_cub *var)
{
	int	i;

	i = ft_strlen(var->paths[0]);
	if (ft_strncmp(&var->paths[0][i - 4], ".png", 5))
		return (ERROR);
	i = ft_strlen(var->paths[1]);
	if (ft_strncmp(&var->paths[1][i - 4], ".png", 5))
		return (ERROR);
	i = ft_strlen(var->paths[2]);
	if (ft_strncmp(&var->paths[2][i - 4], ".png", 5))
		return (ERROR);
	i = ft_strlen(var->paths[3]);
	if (ft_strncmp(&var->paths[3][i - 4], ".png", 5))
		return (ERROR);
	return (0);
}

int	split_info(t_cub *var)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (store_info(var->map[i], var))
			return (ERROR);
		if (store_color_info(var->map[i], var))
			return (ERROR);
		i++;
	}
	if (!var->paths[0] || !var->paths[1] || !var->paths[2] || \
		!var->paths[3] || !var->floor[1] || !var->ceiling[1])
		return (ERROR);
	if (path_validity(var) || color_validity(var))
		return (ERROR);
	if (textures_extension(var))
		return (ERROR);
	return (0);
}
