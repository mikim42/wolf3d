/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:44:19 by mikim             #+#    #+#             */
/*   Updated: 2018/01/18 15:33:12 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <mlx.h>
# include <math.h>

# define WINDOW 1000
# define TEXTURE 64
# define SKY 0x99FFFF
# define GROUND 0xCC6600
# define WHITE 0xFFFFFF

# define KEY 2
# define CLOSE 17

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

/*
** # define TEXTURE_0 (xor_color + 256 * xor_color + 65536 * xor_color)
** # define TEXTURE_1 (256 * xor_color)
** # define TEXTURE_2 (xor_color + 128 * xor_color + 32768 * xor_color)
** # define TEXTURE_3 (65536 * xor_color)
** # define TEXTURE_4 (xor_color + 64 * xor_color + 16384 * xor_color)
** # define TEXTURE_5 (xor_color + 64 * xor_color + 65536 * xor_color)
*/

# define TEXTURE_0 (0x6666FF * (x != y && x != TEXTURE - y))
# define TEXTURE_1 (xy_color + 153 * 256 * xy_color + 60000 * xy_color)
# define TEXTURE_2 (0x006600 * (x % 3))
# define TEXTURE_3 (xor_color + 64 * xor_color + 65536 * xor_color)
# define TEXTURE_4 (65536 * 64 * (x % 8 && y % 8))
# define TEXTURE_5 (0xCC9900 * (y % 8 && 1))

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	char			*img;
	int				*data;
	int				size;
	int				bits;
	int				endian;
}					t_mlx;

typedef struct		s_map
{
	int				**map;
	int				row;
	int				col;
	double			x;
	double			y;
}					t_map;

typedef struct		s_env
{
	t_mlx			mlx;
	t_map			map;
	int				*texture[6];
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				side;
	double			wall_x;
	int				line_hgt;
	double			floor_x;
	double			floor_y;
	double			dist_wall;
	double			dist_pos;
	double			dist_curr;
	double			weight;
	double			curr_floor_x;
	double			curr_floor_y;
	int				floor_text_x;
	int				floor_text_y;
}					t_env;

typedef struct		s_thread
{
	t_env			*e;
	int				n;
}					t_thread;

/*
**					wolf3d
*/

void				wolf3d(t_env *e);
void				cross_hair(t_env *e);

/*
**					raycasting
*/

void				raycasting(t_env *e);
void				calc_ray(t_env *e, int x);
void				dda_algorithm(t_env *e);
void				dda_loop(t_env *e);

/*
**					parse_handler
*/

void				parse(t_env *e, char *map);
void				init_mlx(t_env *e);
void				init_texture(t_env *e);
void				init_map(t_env *e, char *map);
void				init_wolf3d(t_env *e);

/*
**					map_handler
*/

bool				map_size(t_env *e, int fd);
bool				map_start_pos(t_env *e, int fd);
bool				map_create(t_env *e, int fd);
bool				map_alloc(t_env *e);

/*
**					valid_handler
*/

char				**map_valid(t_env *e, char *line, int index);
bool				map_valid_wall(t_env *e);

/*
**					plot_handler
*/

void				plot(t_env *e, int x, int st, int end);
int					get_wall(t_env *e);
void				plot_floor(t_env *e, int x, int end);
void				calc_ray_floor(t_env *e);

/*
**					hook_handler
*/

int					key_hooks(int code, t_env *e);
void				move(t_env *e, int code);
void				rotate(t_env *e, int code);
int					close_hooks(t_env *e);

/*
**					exit_handler
*/

void				ft_exit(t_env *e, char *msg);
void				destroy(t_env *e);

#endif
