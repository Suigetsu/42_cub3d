/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:57:09 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/24 12:51:26 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

mlx_texture_t	*get_image(char *path)
{
	mlx_texture_t	*img;

	img = mlx_load_png(path);
	if (img->width != img->height)
		printf("invalid texture.\n");
	return (img);
}

void	get_tex(t_cub *var)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		var->txt[i] = get_image(var->paths[i]);
		i++;
	}
}
