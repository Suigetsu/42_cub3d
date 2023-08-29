/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:50:48 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/29 21:52:35 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	store_elements(int count, char *element, char **storage)
{
	if (count == 0)
		storage = malloc (sizeof(char *) * 3);
	storage[count] = ft_strdup(element);
	storage[3] = NULL;
}

int	check_valid_elements(int count, t_cub3d *var)
{
	int	fd;

	fd = -1;
	if ((count == 0 && ft_strncmp(var->split[0], "NO", 3) == 0) || \
		(count == 1 && ft_strncmp(var->split[0], "SO", 3) == 0) || \
		(count == 2 && ft_strncmp(var->split[0], "WE", 3) == 0) ||
		(count == 3 && ft_strncmp(var->split[0], "EA", 3) == 0))
	{
		fd = open(var->split[1], O_RDONLY);
		if (fd < 0)
			return (1);
		close (fd);
		return (0);
	}
	return (1);
}

int	check_walls(int fd, int count, t_cub3d *var, char **storage)
{
	char	*line;

	while (++count < 4)
	{
		line = get_next_line(fd);
		if (!line && count < 3)
			return (1);
		var->split = ft_split(line, ' ');
		if (var->split[2] || !var->split[1])
		{
			free (line);
			free_double_ptr(var->split);
			return (1);
		}
		if (check_valid_elements(count, var))
		{
			free (line);
			free_double_ptr(var->split);
			return (1);
		}
		store_elements(count, line, storage);
		free (line);
		free_double_ptr(var->split);
	}
	return (0);
}
