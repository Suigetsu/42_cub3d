/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:03:19 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/30 09:55:52 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	complete_map(t_cub *var)
{
	int	loop;

	loop = 0;
	var->y = 0;
	while (var->map[(int)var->y])
	{
		if (ft_strlen(var->map[(int)var->y]) < var->x_max)
		{
			loop = var->x_max - ft_strlen(var->map[(int)var->y]);
			var->temp = ft_strdup(var->map[(int)var->y]);
			free (var->map[(int)var->y]);
			while (loop > 0)
			{
				var->line = ft_strjoin(var->temp, " ");
				free(var->temp);
				var->temp = ft_strdup(var->line);
				free(var->line);
				loop--;
			}
			var->map[(int)var->y] = ft_strdup(var->temp);
			free(var->temp);
		}
		var->y++;
	}
}

int	check_zero(t_cub *var, float x, float y)
{
	if (((int)x > (int)ft_strlen(var->map[(int)(y - 1)]) - 1) || \
		(var->map[(int)y + 1][(int)x] != '1' && \
		var->map[(int)y + 1][(int)x] != '0' && \
		var->map[(int)y + 1][(int)x] != var->p.dir) || \
		(var->map[(int)y - 1][(int)x] != '1' && \
		var->map[(int)y - 1][(int)x] != '0' && \
		var->map[(int)y - 1][(int)x] != var->p.dir) || \
		(var->map[(int)y][(int)x + 1] != '1' && \
		var->map[(int)y][(int)x + 1] != '0' && \
		var->map[(int)y][(int)x + 1] != var->p.dir) || \
		(var->map[(int)y][(int)x - 1] != '1' && \
		var->map[(int)y][(int)x - 1] != '0' && \
		var->map[(int)y][(int)x - 1] != var->p.dir))
		return (ERROR);
	return (0);
}

int	check_player(t_cub *var, float x, float y)
{
	if (((int)x > (int)ft_strlen(var->map[(int)(y - 1)]) - 1) || \
		(var->map[(int)y + 1][(int)x] != '1' && \
		var->map[(int)y + 1][(int)x] != '0') || \
		(var->map[(int)y - 1][(int)x] != '1' && \
		var->map[(int)y - 1][(int)x] != '0') || \
		(var->map[(int)y][(int)x + 1] != '1' && \
		var->map[(int)y][(int)x + 1] != '0') || \
		(var->map[(int)y][(int)x - 1] != '1' && \
		var->map[(int)y][(int)x - 1] != '0'))
		return (ERROR);
	return (0);
}
