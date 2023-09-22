/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:35:30 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/22 13:17:54 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_filename(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (ft_strncmp(&filename[i - 4], ".cub", 5) == 0)
		return (0);
	return (1);
}

int	parse_info(t_cub *var)
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

int	read_map(char *filename, t_cub *var)
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
		var->temp = ft_strjoin(var->scene, var->line);
		free (var->scene);
		var->scene = ft_strdup(var->temp);
		free (var->temp);
		free (var->line);
		var->line = get_next_line(var->fd);
	}
	close (var->fd);
	return (0);
}
