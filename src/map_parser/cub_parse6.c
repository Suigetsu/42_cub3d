/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:03:19 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/24 09:59:49 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
