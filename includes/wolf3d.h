/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:44:19 by mikim             #+#    #+#             */
/*   Updated: 2018/01/04 22:46:38 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <mlx.h>
# include <math.h>

# define THREAD 4

# define WID_RATE 100
# define HGT_RATE 100

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				wid;
	int				hgt;
	int				*data;
	int				size;
	int				bits;
	int				endian;
}					t_mlx;

typedef struct		s_thread
{
	pthread_mutex_t	mutex;
	int				n[THREAD];
}					t_thread;

typedef struct		s_map
{
	int				row;
	int				col;
	int				*map;
}					t_map;

typedef struct		s_env
{
	t_mlx			mlx;
	t_thread		thread;
	t_map			map;
}					t_env;



#endif
