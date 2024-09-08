/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:07:50 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/29 10:30:14 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_phase1(t_cub *var)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (var->paths[i])
			free (var->paths[i]);
		i++;
	}
	if (var->scene)
		free (var->scene);
	if (var->map)
		free_double_ptr(var->map);
	if (var->floor)
		free_double_ptr(var->floor);
	if (var->ceiling)
		free_double_ptr(var->ceiling);
	if (var->split)
		free_double_ptr(var->split);
}
