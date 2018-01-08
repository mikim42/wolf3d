/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:52:07 by mikim             #+#    #+#             */
/*   Updated: 2018/01/08 01:17:17 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		close_hooks(t_env *e)
{
	ft_exit(e, NULL);
	return (0);
}

void	rotate(t_env *e, int code)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	if (code == 124)
	{
		tmp_dir_x = e->dir_x;
		e->dir_x = tmp_dir_x * cos(-0.1) - e->dir_y * sin(-0.1);
		e->dir_y = tmp_dir_x * sin(-0.1) + e->dir_y * cos(-0.1);
		tmp_plane_x = e->plane_x;
		e->plane_x = tmp_plane_x * cos(-0.1) - e->plane_y * sin(-0.1);
		e->plane_y = tmp_plane_x * sin(-0.1) + e->plane_y * cos(-0.1);
	}
	if (code == 123)
	{
		tmp_dir_x = e->dir_x;
		e->dir_x = tmp_dir_x * cos(0.1) - e->dir_y * sin(0.1);
		e->dir_y = tmp_dir_x * sin(0.1) + e->dir_y * cos(0.1);
		tmp_plane_x = e->plane_x;
		e->plane_x = tmp_plane_x * cos(0.1) - e->plane_y * sin(0.1);
		e->plane_y = tmp_plane_x * sin(0.1) + e->plane_y * cos(0.1);
	}
}

void	move(t_env *e, int code)
{
	if (code == 126)
	{
		if (!e->map.map[(int)(e->map.x + e->dir_x * 0.1)][(int)e->map.y])
			e->map.x += e->dir_x * 0.1;
		if (!e->map.map[(int)e->map.x][(int)(e->map.y + e->dir_y * 0.1)])
			e->map.y += e->dir_y * 0.1;
	}
	if (code == 125)
	{
		if (!e->map.map[(int)(e->map.x - e->dir_x * 0.1)][(int)e->map.y])
			e->map.x -= e->dir_x * 0.1;
		if (!e->map.map[(int)e->map.x][(int)(e->map.y - e->dir_y * 0.1)])
			e->map.y -= e->dir_y * 0.1;
	}
}

int		key_hooks(int code, t_env *e)
{
	code == 53 ? ft_exit(e, NULL) : 0;
	if (code == 124 || code == 123)
		rotate(e, code);
	if (code == 126 || code == 125)
		move(e, code);
	mlx_destroy_image(e->mlx.mlx, e->mlx.img);
	init_mlx(e);
	wolf3d(e);
	return (0);
}
