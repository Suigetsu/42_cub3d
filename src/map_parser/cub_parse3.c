/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:29:50 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/19 17:22:06 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	color_validity(t_cub *var)
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
	return (0);
}

int	path_validity(t_cub *var)
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
