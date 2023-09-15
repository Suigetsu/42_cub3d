/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:22:09 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/15 16:20:09 by mlagrini         ###   ########.fr       */
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
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"


# define T_SIZE 80
# define WIDTH 5120 / 4
# define HEIGHT 2880 / 4
# define ERROR -1
# define RADIANS (M_PI / 180)
# define FOV 60 * RADIANS
# define ROT_ANGLE M_PI / 2
# define MOVE_SPEED 3
# define ROT_SPEED 3 * RADIANS
# define NUM_RAYS (T_SIZE / 2);

typedef	struct s_ray
{
	int	inter_x;
	int	inter_y;
	float	horizon;
	float	vertical;
	float	start;
	float	end;
	float	step_x;
	float	step_y;
}		t_ray;

typedef struct	s_player
{
	float	p_pos_x;
	float	p_pos_y;
	float	h;
	float	k;
	float	end_x;
	float	end_y;
	float	radius;
	float	turn_dir;
	float	walk_dir;
	float	ray_angle;
	float	direction;
	float	ray_dir;
	char	dir;
}				t_player;

typedef struct s_cub3d
{
	float		x_max;
	float		y_max;
	float		x;
	float		y;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
	int			fd;
	char		**ids;
	char		**split;
	char		**north;
	char		**south;
	char		**west;
	char		**east;
	char		**floor;
	char		**ceiling;
	char		*scene;
	char		**fc;
	char		**map;
	char		*line;
	char		*temp;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	p;
	t_ray		ray;
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
float	get_direction(t_cub3d *var);
void	cast_rays(t_cub3d *var);
void	rotate_player(t_cub3d *var, float angle, int key);
int		around_space(t_cub3d *var, int y, int x);
int		check_map(char *filename, t_cub3d *var);
void	init_vars(t_cub3d *var, int ac, char **av);
int		run_mlx(t_cub3d *var);
void	keyhook(void *param);
void	find_player_pos(t_cub3d *var);
void	draw_line(mlx_image_t *img, t_cub3d *var, int color);
void	draw_minimap(t_cub3d *var, mlx_image_t *img);
void	draw_player_pixels(t_cub3d *var, int color, mlx_image_t *img);
void	fix_angle(t_cub3d *var);
void	draw_pixels(float x, float y, int color, mlx_image_t *img);


#endif
