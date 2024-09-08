/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:15:45 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/30 16:48:46 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	free_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free (ptr);
	ptr = NULL;
}

int	cub_atoi(const char *str)
{
	int		i;
	int		result;
	char	*trim;

	i = 0;
	result = 0;
	trim = ft_strtrim(str, " ");
	if (!(trim[i] >= '0' && trim[i] <= '9'))
		return (ERROR);
	while (trim[i] >= '0' && trim[i] <= '9')
	{
		result = result * 10 + trim[i] - '0';
		if (result > 255)
			return (free(trim), ERROR);
		i++;
	}
	if (trim[i])
		return (free(trim), ERROR);
	return (free(trim), result);
}
