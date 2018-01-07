/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:52:07 by mikim             #+#    #+#             */
/*   Updated: 2018/01/06 18:17:04 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		close_hooks(t_env *e)
{
	ft_exit(e, NULL);
	return (0);
}

int		expose_hooks(t_env *e)
{
	if (e->mlx.expose)
		wolf3d(e);
	else
		e->mlx.expose = 1;
	return (0);
}

int		motion_hooks(int x, int y, t_env *e)
{
	if (e->mlx.motion)
	{
		e->mlx.motion_x = x;
		e->mlx.motion_y = y;
		wolf3d(e);
	}
	return (0);
}

int		mouse_hooks(int button, int x, int y, t_env *e)
{
	button = x + y + (int)e;
	return (0);
}

int		key_hooks(int code, t_env *e)
{
	code == 53 ? ft_exit(e, NULL) : 0;
	if (code == 126)
	{
		double olddirx = e->dir_x;
		e->dir_x = e->dir_x * cos(-0.1) - e->dir_y * sin(-0.1);
		e->dir_y = olddirx * sin(-0.1) + e->dir_y * cos(-0.1);
		double oldPlaneX = e->plane_x;
		e->plane_x = e->plane_x * cos(-0.1) - e->plane_y * sin(-0.1);
		e->plane_y = oldPlaneX * sin(-0.1) + e->plane_y * cos(-0.1);
	}
	mlx_destroy_image(e->mlx.mlx, e->mlx.img);
	e->mlx.img = mlx_new_image(e->mlx.mlx, e->mlx.wid, e->mlx.hgt);
	e->mlx.data = (int*)mlx_get_data_addr(e->mlx.img, &e->mlx.bits,
	&e->mlx.size, &e->mlx.endian);
	wolf3d(e);
	return (0);
}
