/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:10:00 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/29 21:52:12 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_filename(char *filename)
{
	int	i;
	
	i = ft_strlen(filename);
	if (ft_strncmp(&filename[i - 4], ".cub", 5) == 0)
		return (0);
	return (1);
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
		if (cubtoi(count, var))
			return (1);
		return (0);
	}
	return (1);
}

void	store_elements(int count, char *element, char **storage)
{
	if (count == 0)
		storage = malloc (sizeof(char *) * 3);
	storage[count] = ft_strdup(element);
	storage[3] = NULL;
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

int	check_fc(int fd, int count, t_cub3d *var, char **storage)
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
		
	}
}

void	check_map_content(t_cub3d *var, char *filename, int loop)
{
	int		fd;
	
	fd = open(filename, O_RDONLY);
	if (fd > 0)
		return ;
	if (check_walls(fd, -1, var, var->ids))
		exit (1);
	var->line = get_next_line(fd);
	if (!var->line || ft_strncmp(var->line, "\n", 2))
		exit (1);
	if (check_fc(fd, -1, var, var->fc))
		exit (1);
	close (fd);
}
