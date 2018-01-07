/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:44:19 by mikim             #+#    #+#             */
/*   Updated: 2018/01/06 18:17:07 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <pthread.h>

# define THREAD 4

# define DEFAULT 1000
# define WID_RATE 100
# define HGT_RATE 100
# define WID_MAX 1900
# define WID_MIN 100
# define HGT_MAX 1200
# define HGT_MIN 100
# define TEXTURE 64
# define WHITE 0xFFFFFF

# define KEY 2
# define MOUSE 4
# define MOTION 6
# define EXPOSE 12
# define CLOSE 17

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	char			*img;
	int				wid;
	int				hgt;
	int				*data;
	int				size;
	int				bits;
	int				endian;
	int				expose;
	int				motion;
	int				motion_x;
	int				motion_y;
}					t_mlx;

typedef struct		s_map
{
	int				**map;
	int				row;
	int				col;
	int				y;
	int				x;
}					t_map;

typedef struct		s_env
{
	t_mlx			mlx;
	t_map			map;
	pthread_mutex_t	mutex;
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
	int				map_y;
	int				map_x;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				side;
	int				line_hgt;
	int				draw_st;
	int				draw_end;
	int				text_n;
	double			wall_x;
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
char				**map_valid(t_env *e, char *line);

/*
**					plot_handler
*/

void				plot(t_env *e, int x);

/*
**					hook_handler
*/

int					key_hooks(int code, t_env *e);
int					mouse_hooks(int button, int x, int y, t_env *e);
int					motion_hooks(int x, int y, t_env *e);
int					expose_hooks(t_env *e);
int					close_hooks(t_env *e);

/*
**					exit_handler
*/

void				ft_exit(t_env *e, char *msg);
void				destroy(t_env *e);

/*
**
*/



/*
**
*/



/*
**
*/




#endif
