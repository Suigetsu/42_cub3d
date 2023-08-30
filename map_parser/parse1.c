/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:10:00 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/30 14:05:44 by mlagrini         ###   ########.fr       */
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

// void	check_map_content(t_cub3d *var, char *filename)
// {
// 	int		fd;
	
// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		return ;
// 	if (check_walls(fd, -1, var, var->ids))
// 		exit (1);
// 	printf("debug\n");
// 	var->line = get_next_line(fd);
// 	if (!var->line || ft_strncmp(var->line, "\n", 2))
// 		exit (1);
// 	if (check_fc(fd, -1, var))
// 		exit (1);
// 	close (fd);
// }
