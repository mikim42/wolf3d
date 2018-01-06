/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:49:47 by mikim             #+#    #+#             */
/*   Updated: 2018/01/06 13:17:57 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	plot(t_env *e, int x)
{
	int y;
	int d;
	int texture_x;
	int texture_y;
	int color;

	e->text_n = e->map.map[e->map_x][e->map_y] - 1;
	if (!e->side)
		e->wall_x = e->ray_pos_y + e->perp_wall_dist * e->ray_dir_y;
	else
		e->wall_x = e->ray_pos_x + e->perp_wall_dist * e->ray_dir_x;
	e->wall_x -= floor(e->wall_x);
	texture_x = (int)e->wall_x * (double)TEXTURE;
	if((!e->side && e->ray_dir_x > 0) || (e->side && e->ray_dir_y < 0))
		texture_x = TEXTURE - texture_x - 1;
	y = -1;
	while (++y < e->draw_st)
	{
		d = y * 256 - e->mlx.hgt * 128 + e->line_hgt * 128;
		texture_y = ((d * TEXTURE) / e->line_hgt) / 256;
		color = e->texture[e->text_n][TEXTURE * texture_y + texture_x];
		if (e->side)
			color = (color >> 1) & 8355711;
		e->mlx.data[(y * e->mlx.size / 4) + (x * 4)] = color;
	}
}
