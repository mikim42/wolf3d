/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:52:07 by mikim             #+#    #+#             */
/*   Updated: 2018/01/07 14:41:53 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		close_hooks(t_env *e)
{
	ft_exit(e, NULL);
	return (0);
}

int		key_hooks(int code, t_env *e)
{
	code == 53 ? ft_exit(e, NULL) : 0;
	if (code == 124)
	{
		double olddirx = e->dir_x;
		e->dir_x = olddirx * cos(-0.1) - e->dir_y * sin(-0.1);
		e->dir_y = olddirx * sin(-0.1) + e->dir_y * cos(-0.1);
		double oldplanex = e->plane_x;
		e->plane_x = oldplanex * cos(-0.1) - e->plane_y * sin(-0.1);
		e->plane_y = oldplanex * sin(-0.1) + e->plane_y * cos(-0.1);
	}
	if (code == 123)
	{
		double olddirx = e->dir_x;
		e->dir_x = olddirx * cos(0.1) - e->dir_y * sin(0.1);
		e->dir_y = olddirx * sin(0.1) + e->dir_y * cos(0.1);
		double oldplanex = e->plane_x;
		e->plane_x = oldplanex * cos(0.1) - e->plane_y * sin(0.1);
		e->plane_y = oldplanex * sin(0.1) + e->plane_y * cos(0.1);
	}
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
	mlx_destroy_image(e->mlx.mlx, e->mlx.img);
	init_mlx(e);
	wolf3d(e);
	return (0);
}
