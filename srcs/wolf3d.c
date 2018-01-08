/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:09:38 by mikim             #+#    #+#             */
/*   Updated: 2018/01/07 16:49:29 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	cross_hair(t_env *e)
{
	e->mlx.data[(WINDOW / 2 - 1) * e->mlx.size / 4 + (WINDOW / 2)] = WHITE;
	e->mlx.data[(WINDOW / 2 - 2) * e->mlx.size / 4 + (WINDOW / 2)] = WHITE;
	e->mlx.data[(WINDOW / 2 + 1) * e->mlx.size / 4 + (WINDOW / 2)] = WHITE;
	e->mlx.data[(WINDOW / 2 + 2) * e->mlx.size / 4 + (WINDOW / 2)] = WHITE;
	e->mlx.data[(WINDOW / 2) * e->mlx.size / 4 + (WINDOW / 2) - 1] = WHITE;
	e->mlx.data[(WINDOW / 2) * e->mlx.size / 4 + (WINDOW / 2) - 2] = WHITE;
	e->mlx.data[(WINDOW / 2) * e->mlx.size / 4 + (WINDOW / 2) + 1] = WHITE;
	e->mlx.data[(WINDOW / 2) * e->mlx.size / 4 + (WINDOW / 2) + 2] = WHITE;
}

void	wolf3d(t_env *e)
{
	raycasting(e);
	cross_hair(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	mlx_hook(e->mlx.win, KEY, 0, key_hooks, e);
	mlx_hook(e->mlx.win, CLOSE, 0, close_hooks, e);
	mlx_loop(e->mlx.mlx);
}
