/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse4_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:48:07 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/29 20:24:51 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	skip_info(t_cub *var)
{
	int	count;

	count = 0;
	while (count < 6)
	{
		if (!ft_strncmp(var->line, "NO ", 3) || \
		!ft_strncmp(var->line, "SO ", 3) || \
		!ft_strncmp(var->line, "WE ", 3) || \
		!ft_strncmp(var->line, "EA ", 3) || !ft_strncmp(var->line, "F ", 2) || \
		!ft_strncmp(var->line, "C ", 2))
			count++;
		free (var->line);
		var->line = get_next_line(var->fd);
	}
}

int	is_space_only(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != ' ' || line[i] != '\t') && line[i])
			return (0);
		i++;
	}
	return (1);
}

int	copy_map(t_cub *var)
{
	free(var->scene);
	var->scene = ft_strdup("");
	while (var->line)
	{
		if (ft_strncmp(var->line, "\n", 2) == 0 || \
			ft_strlen(var->line) == 300 || var->y_max >= 300)
			return (ERROR);
		var->temp = ft_strjoin(var->scene, var->line);
		free (var->scene);
		var->scene = ft_strdup(var->temp);
		free (var->temp);
		if (ft_strlen(var->line) > var->x_max)
			var->x_max = ft_strlen(var->line) - 1;
		var->y_max++;
		free (var->line);
		var->line = get_next_line(var->fd);
	}
	return (0);
}

int	check_map(char *filename, t_cub *var)
{
	int	count;

	count = 0;
	var->fd = open(filename, O_RDONLY);
	var->line = get_next_line(var->fd);
	skip_info(var);
	while (var->line)
	{
		if (ft_strncmp(var->line, "\n", 2) && !is_space_only(var->line))
		{
			if (copy_map(var))
			{
				free(var->line);
				close (var->fd);
				return (ERROR);
			}
			break ;
		}
		free (var->line);
		var->line = get_next_line(var->fd);
	}
	close(var->fd);
	return (0);
}
