/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:03:19 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/23 13:29:13 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_x2(t_cub *var, int y, int x, int flag)
{
	while (x < (int)ft_strlen(var->map[y]) - 2)
	{
		if (var->map[y][x + 1] == var->map[y][x])
			x += 1;
		else if (var->map[y][x + 1] == '1')
			break ;
		else
			return (0);
	}
	flag += 1;
	return (flag);
}

int	check_x(t_cub *var, int y, int x, int flag)
{
	while (x > 0)
	{
		if (var->map[y][x - 1] == var->map[y][x])
			x -= 1;
		else if (var->map[y][x - 1] == '1')
			break ;
		else
			return (0);
	}
	flag += 1;
	return (flag);
}

int	check_y2(t_cub *var, int y, int x, int flag)
{
	while (y < var->y_max - 2)
	{
		if (var->map[y + 1][x] == var->map[y][x])
			y += 1;
		else if (var->map[y + 1][x] == '1')
			break ;
		else
			return (0);
	}
	flag += 1;
	return (flag);
}

int	check_y(t_cub *var, int y, int x, int flag)
{
	while (y > 0)
	{
		if (var->map[y - 1][x] == var->map[y][x])
			y -= 1;
		else if (var->map[y - 1][x] == '1')
			break ;
		else
			return (0);
	}
	flag += 1;
	return (flag);
}

int	around_space(t_cub *var, int y, int x, char component)
{
	int	y_flag;
	int	x_flag;

	if (x == 0 && component == ' ')
	{
		x_flag = check_x2(var, y, x, 0);
		if (x_flag != 1)
			return (ERROR);
		return (0);
	}
	y_flag = check_y(var, y, x, 0);
	y_flag = check_y2(var, y, x, y_flag);
	if (y_flag != 2)
		return (ERROR);
	x_flag = check_x(var, y, x, 0);
	x_flag = check_x2(var, y, x, x_flag);
	if (x_flag != 2)
		return (ERROR);
	return (0);
}
