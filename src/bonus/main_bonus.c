/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:21:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/30 16:48:46 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_cub		var;
	int			i;

	i = 0;
	if (init_vars(&var, ac, av))
		return (1);
	run_mlx(&var);
	free_phase1(&var);
	mlx_delete_image(var.mlx, var.img);
	while (i < 4)
	{
		if (var.txt[i])
			mlx_delete_texture(var.txt[i]);
		i++;
	}
	mlx_terminate(var.mlx);
	return (0);
}
