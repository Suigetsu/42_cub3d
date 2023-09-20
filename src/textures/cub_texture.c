/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:57:09 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/20 10:23:28 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_tex(t_cub *var)
{
    int	*walltext;
	int	i;
	int	j;

	walltext = (int*) malloc(sizeof(int) * (int)TEX_WIDTH * (int)TEX_HEIGHT);
	i = 0;
	j = 0;
	while (i < TEX_WIDTH)
	{
		while (j < TEX_HEIGHT)
		{
			if (i % 8 && j % 8)
				walltext[(TEX_WIDTH * j) + i] = 0xFF0000FF;
			else
				walltext[(TEX_WIDTH * j) + i] = 0xFF000000;
			j++;
		}
		i++;
	}
}