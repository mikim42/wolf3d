/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:09:38 by mikim             #+#    #+#             */
/*   Updated: 2018/01/05 22:42:00 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	cross_hair(t_env *e)
{
	e->data[(e->hgt / 2 - 1) * e->size / 4 + (e->wid / 2)] = WHITE;
	e->data[(e->hgt / 2 - 2) * e->size / 4 + (e->wid / 2)] = WHITE;
	e->data[(e->hgt / 2 + 1) * e->size / 4 + (e->wid / 2)] = WHITE;
	e->data[(e->hgt / 2 + 2) * e->size / 4 + (e->wid / 2)] = WHITE;
	e->data[(e->hgt / 2) * e->size / 4 + (e->wid / 2) - 1] = WHITE;
	e->data[(e->hgt / 2) * e->size / 4 + (e->wid / 2) - 2] = WHITE;
	e->data[(e->hgt / 2) * e->size / 4 + (e->wid / 2) + 1] = WHITE;
	e->data[(e->hgt / 2) * e->size / 4 + (e->wid / 2) + 2] = WHITE;
}

void	wolf3d(t_env *e)
{
	raycasting(e);
	cross_hair(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	mlx_hook(e->mlx.win, KEY, 0, key_hooks, e);
	mlx_hook(e->mlx.win, MOTION, 0, motion_hooks, e);
	mlx_hook(e->mlx.win, MOUSE, 0, mouse_hooks, e);
	mlx_hook(e->mlx.win, EXPOSE, 0, expose_hooks, e);
	mlx_hook(e->mlx.win, CLOSE, 0, close_hooks, e);
}