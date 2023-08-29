/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:22:09 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/29 20:01:33 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define WIDTH 700
# define HEIGHT 400
# define ERROR -1

typedef struct s_cub3d
{
	int		i;
	int		x;
	int		y;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	char	**split;
	char	**ids;
	char	**fc;
	char	**map;
	char	*line;
}				t_cub3d;

int		check_filename(char *filename);
int		filelen(char *filename);
void	free_double_ptr(void **ptr);
int		cub_atoi(const char *str);

#endif
