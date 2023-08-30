/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:33:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/29 22:42:54 by mlagrini         ###   ########.fr       */
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
	arr[1] = ft_substr(str, j, (i - j)+ 1);
	i++;
	arr[2] = ft_substr(str, i, ft_strlen(str) + i);
	arr[3] = NULL;
	return (arr);
}

int	store_color_info(int count, t_cub3d *var)
{
	char	**arr;
	int		i;

	i = 0;
	arr = colors_split(var->split[1]);
	if (!arr)
		return (1);
	if (cub_atoi(arr[0]) == ERROR || cub_atoi(arr[1]) == ERROR || \
		cub_atoi(arr[2]) == ERROR)
		return (1);
	if (count == 0)
	{
		var->f_r = cub_atoi(arr[0]);
		var->f_g = cub_atoi(arr[1]);
		var->f_b = cub_atoi(arr[2]);
	}
	else if (count == 1)
	{
		var->c_r = cub_atoi(arr[0]);
		var->c_g = cub_atoi(arr[1]);
		var->c_b = cub_atoi(arr[2]);
	}
	free_double_ptr(arr);
	return (0);
}

int	check_valid_elements2(int count, t_cub3d *var)
{
	int		i;

	i = 0;
	if ((count == 0 && ft_strncmp(var->split[0], "F", 2) == 0) || \
		(count == 1 && ft_strncmp(var->split[0], "C", 2) == 0))
	{
		if (store_color_info(count, var))
			return (1);
		return (0);
	}
	return (1);
}

int	check_fc(int fd, int count, t_cub3d *var)
{
	char	*line;
	
	while (++count < 2)
	{
		line = get_next_line(fd);
		if (!line && count < 2)
			return (1);
		var->split = ft_split(line, ' ');
		if (var->split[2] || !var->split[1])
		{
			free (line);
			free_double_ptr(var->split);
			return (1);
		}
		if (check_valid_elements2(count, var))
		{
			free (line);
			free_double_ptr(var->split);
			return (1);
		}
		free (line);
		free_double_ptr(var->split);
	}
	return (0);
}
