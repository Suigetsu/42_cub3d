/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:22:09 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/01 17:21:09 by mlagrini         ###   ########.fr       */
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
	int		x_max;
	int		y_max;
	int		x;
	int		y;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	int		fd;
	char	**ids;
	char	**split;
	char	**north;
	char	**south;
	char	**west;
	char	**east;
	char	**floor;
	char	**ceiling;
	char	*scene;
	char	**fc;
	char	**map;
	char	*line;
}				t_cub3d;

int		check_filename(char *filename);
void	free_double_ptr(char **ptr);
int		cub_atoi(const char *str);
int		read_map(char *filename, t_cub3d *var);
int		parse_info(t_cub3d *var);
int		path_validity(t_cub3d *var);
int		split_info(t_cub3d *var);
int		path_validity(t_cub3d *var);
int		color_validity(t_cub3d *var);
void	free_for_exit(t_cub3d *var, int exit_status);
void	free_for_map(t_cub3d *var);
int		is_map_valid(t_cub3d *var);
int		around_space(t_cub3d *var, int y, int x);
int		check_map(char *filename, t_cub3d *var);

#endif
