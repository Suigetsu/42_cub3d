/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:40:49 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/10 13:05:42 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_suroundings(t_cub3d *var)
{
	while (var->map[0][(int)var->x])
	{
		if (var->map[0][(int)var->x] != '1' && var->map[0][(int)var->x] != ' ')
			return (ERROR);
		var->x++;
	}
	var->x = 0;
	while (var->map[(int)var->y_max - 1][(int)var->x])
	{
		if (var->map[(int)var->y_max - 1][(int)var->x] != '1' && \
			var->map[(int)var->y_max - 1][(int)var->x] != ' ')
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
		while (var->map[(int)var->y][(int)var->x])
		{
			if (var->x == 0)
			{
				if (var->map[(int)var->y][(int)var->x] != '1' && \
					var->map[(int)var->y][(int)var->x] != ' ')
					return (ERROR);
			}
			if (var->map[(int)var->y][(int)var->x] == ' ')
			{
				if (around_space(var, var->y, var->x))
					return (ERROR);
			}
			if (var->map[(int)var->y][ft_strlen(var->map[(int)var->y]) - 1] != '1')
				return (ERROR);

			var->x++;
		}
		var->y++;
	}
	return (0);
}

void	find_player_pos(t_cub3d *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'N' || var->map[i][j] == 'S' || \
					var->map[i][j] == 'E' || var->map[i][j] == 'W')
				{
					var->p.p_pos_x = j * T_SIZE;
					var->p.p_pos_y = i * T_SIZE;
					var->p.dir = var->map[i][j];
					return ;
				}
			j++;
		}
		i++;
	}
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
	find_player_pos(var);
	return (0);
}
