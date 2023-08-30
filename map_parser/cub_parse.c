/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:35:30 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/30 14:51:04 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	comma_count(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] != ',')
			i++;
		if (str[i] == ',')
			count++;
		if (str[i])
			i++;
	}
	return (count);
}

char	**colors_split(char *str)
{
	char	**arr;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (comma_count(str) != 2)
		return (NULL);
	arr = malloc(sizeof(char *) * 4);
	while (str[i] && str[i] != ',')
		i++;
	arr[0] = ft_substr(str, 0, i);
	i++;
	j = i;
	while (str[i] && str[i] != ',')
		i++;
	arr[1] = ft_substr(str, j, (i - j));
	i++;
	arr[2] = ft_substr(str, i, ft_strlen(str) + i);
	arr[3] = NULL;
	return (arr);
}

int	color_validity(t_cub3d *var)
{
	if (comma_count(var->floor[1]) != 2 || comma_count(var->ceiling[1]) != 2)
		return (ERROR);
	var->split = colors_split(var->floor[1]);
	if (cub_atoi(var->split[0]) == ERROR || \
		cub_atoi(var->split[1]) == ERROR || cub_atoi(var->split[2]) == ERROR)
		return (ERROR);
	var->f_r = cub_atoi(var->split[0]);
	var->f_g = cub_atoi(var->split[1]);
	var->f_b = cub_atoi(var->split[2]);
	free_double_ptr(var->split);
	var->split = colors_split(var->ceiling[1]);
	if (cub_atoi(var->split[0]) == ERROR || \
		cub_atoi(var->split[1]) == ERROR || cub_atoi(var->split[2]) == ERROR)
		return (ERROR);
	var->c_r = cub_atoi(var->split[0]);
	var->c_g = cub_atoi(var->split[1]);
	var->c_b = cub_atoi(var->split[2]);
	free_double_ptr(var->split);
	return (0);
}

int	path_validity(t_cub3d *var)
{
	var->fd = open(var->north[1], O_RDONLY);
	if (var->fd < 0)
		return (ERROR);
	close (var->fd);
	var->fd = open(var->south[1], O_RDONLY);
	if (var->fd < 0)
		return (ERROR);
	close (var->fd);
	var->fd = open(var->west[1], O_RDONLY);
	if (var->fd < 0)
		return (ERROR);
	close (var->fd);
	var->fd = open(var->east[1], O_RDONLY);
	if (var->fd < 0)
		return (ERROR);
	close (var->fd);
	return (0);
}

int	store_info(char *info_line, t_cub3d *var)
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
			return (ERROR);
		if (store_color_info(var->map[i], var))
			return (ERROR);
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

int	parse_info(t_cub3d *var)
{
	int	i;

	i = 0;
	var->map = ft_split(var->scene, '\n');
	while (i < 6)
	{
		if (ft_strncmp(var->map[i], "NO ", 3) && \
		ft_strncmp(var->map[i], "SO ", 3) && \
		ft_strncmp(var->map[i], "WE ", 3) && \
		ft_strncmp(var->map[i], "EA ", 3) && \
		ft_strncmp(var->map[i], "F ", 2) && \
		ft_strncmp(var->map[i], "C ", 2))
			return (ERROR);
		i++;
	}
	if (split_info(var))
		return (ERROR);
	return (0);
}

int	read_map(char *filename, t_cub3d *var)
{
	var->fd = open(filename, O_RDONLY);
	if (var->fd < 0)
		return (ERROR);
	var->line = get_next_line(var->fd);
	if (!var->line)
	{
		close (var->fd);
		return (ERROR);
	}
	var->scene = ft_strdup("");
	while (var->line)
	{
		var->scene = ft_strjoin(var->scene, var->line);
		free (var->line);
		var->line = get_next_line(var->fd);
	}
	close (var->fd);
	return (0);
}
