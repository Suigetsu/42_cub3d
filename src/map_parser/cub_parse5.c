/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:40:49 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/04 13:05:44 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_suroundings(t_cub3d *var)
{
	while (var->map[0][var->x])
	{
		if (var->map[0][var->x] != '1' && var->map[0][var->x] != ' ')
			return (ERROR);
		var->x++;
	}
	var->x = 0;
	while (var->map[var->y_max - 1][var->x])
	{
		if (var->map[var->y_max - 1][var->x] != '1' && \
			var->map[var->y_max - 1][var->x] != ' ')
			return (ERROR);
		var->x++;
	}
	var->x = 0;
	return (0);
}

int	invalid_char(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' && \
				map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' && \
				map[i][j] != 'W')
				return (ERROR);
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
					map[i][j] == 'E' || map[i][j] == 'W')
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (ERROR);
	return (0);
}

int	check_inside(t_cub3d *var)
{
	var->y = 1;
	while (var->y < var->y_max - 2)
	{
		var->x = 0;
		while (var->map[var->y][var->x])
		{
			if (var->x == 0)
			{
				if (var->map[var->y][var->x] != '1' && \
					var->map[var->y][var->x] != ' ')
					return (ERROR);
			}
			if (var->map[var->y][var->x] == ' ')
			{
				if (around_space(var, var->y, var->x))
					return (ERROR);
			}
			var->x++;
		}
		var->y++;
	}
	return (0);
}

int	is_map_valid(t_cub3d *var)
{
	var->map = ft_split(var->scene, '\n');
	if (invalid_char(var->map))
		return (ERROR);
	if (check_suroundings(var))
		return (ERROR);
	if (check_inside(var))
		return (ERROR);
	return (0);
}
