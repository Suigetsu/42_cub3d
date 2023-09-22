/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:21:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/22 18:07:58 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mmain(int ac, char **av)
{
	t_cub		var;

	if(init_vars(&var, ac, av))
		return (1);
	if (run_mlx(&var))
		free_for_exit(&var, 1);
	return (0);
}

int main(int ac, char **av)
{
	int i = mmain(ac, av);
	system("leaks cub3d");
	return (i);
}
