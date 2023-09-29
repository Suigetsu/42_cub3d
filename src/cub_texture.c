/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:57:09 by hrahmane          #+#    #+#             */
/*   Updated: 2023/09/29 13:48:59 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

mlx_texture_t	*get_image(char *path)
{
	mlx_texture_t	*img;

	img = mlx_load_png(path);
	if (!img)
	{
		printf("Error\ninvalid texture.\n");
		return (NULL);
	}
	if (img->width != img->height)
	{
		printf("Error\ninvalid texture.\n");
		mlx_delete_texture(img);
		return (NULL);
	}
	return (img);
}

int	get_tex(t_cub *var)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		var->txt[i] = get_image(var->paths[i]);
		if (!var->txt[i])
			return (ERROR);
		i++;
	}
	return (0);
}
