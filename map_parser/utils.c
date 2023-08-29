/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:15:45 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/28 20:13:20 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_double_ptr(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free (ptr);
}

int	cub_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (ERROR);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (result > 255)
			return (ERROR);
		i++;
	}
	if (str[i])
		return (ERROR);
	return (result);
}
