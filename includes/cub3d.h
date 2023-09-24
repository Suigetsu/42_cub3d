/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:22:09 by mlagrini          #+#    #+#             */
/*   Updated: 2023/09/24 10:01:04 by mlagrini         ###   ########.fr       */
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

# define T_SIZE 64
# define WIDTH 1280
# define HEIGHT 720
# define ERROR -1
# define MINIMAP_SF 0.2
# define V_AXIS 0
# define H_AXIS 1

typedef struct s_ray
{
	int		dx;
	int		dy;
	int		err;
	int		e2;
	int		inter_x;
	int		inter_y;
	int		step;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	float	x;
	float	y;
	float	horizon;
	float	vertical;
	float	start;
	float	endx_h;
	float	endy_h;
	float	endx_v;
	float	endy_v;
	float	step_x;
	float	step_y;
	float	distance;
	float	inter_axis;
}		t_ray;

typedef struct s_player
{
	float	radians;
	float	fov;
	float	rot_speed;
	float	move_speed;
	float	rotation_angle;
	float	p_pos_x;
	float	p_pos_y;
	float	x;
	float	y;
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

typedef struct s_cub
{
	float			x_max;
	float			y_max;
	float			x;
	float			y;
	int				i;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_r;
	int				c_g;
	int				c_b;
	int				fd;
	char			**ids;
	char			**split;
	char			**north;
	char			**south;
	char			**west;
	char			**east;
	char			**floor;
	char			**ceiling;
	char			*scene;
	char			**fc;
	char			**map;
	char			*line;
	char			*temp;
	char			*paths[4];
	int				x_step;
	int				y_step;
	mlx_texture_t	*txt[4];
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		p;
	t_ray			ray;
}				t_cub;

int		check_filename(char *filename);
void	free_double_ptr(char **ptr);
int		cub_atoi(const char *str);
int		read_map(char *filename, t_cub *var);
int		parse_info(t_cub *var);
int		path_validity(t_cub *var);
int		split_info(t_cub *var);
int		path_validity(t_cub *var);
int		color_validity(t_cub *var);
void	free_for_exit(t_cub *var, int exit_status);
void	free_for_map(t_cub *var);
int		is_map_valid(t_cub *var);
float	get_direction(t_cub *var);
int		check_zero(t_cub *var, float x, float y);
int		check_map(char *filename, t_cub *var);
int		init_vars(t_cub *var, int ac, char **av);
int		run_mlx(t_cub *var);
void	keyhook(void *param);
void	find_player_pos(t_cub *var);
void	draw_line(t_cub *var, mlx_image_t *img);
void	draw_minimap(t_cub *var, mlx_image_t *img);
void	draw_player_pixels(t_cub *var, int color, mlx_image_t *img);
void	draw_pixels(float x, float y, int color, mlx_image_t *img);
void	fix_any_angle(float	*angle);
bool	check_wall(t_cub *var, float x, float y);
void	cast_rays(t_cub *var);
float	horizontal_distance(t_cub *var);
float	vertical_distance(t_cub *var);
void	draw_3d_projection(t_cub *var);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	init_window(t_cub *var);
void	free_phase1(t_cub *var);
void	get_tex(t_cub *var);
int		facing_up_down(t_cub *var);
int		facing_right_left(t_cub *var);
#endif
