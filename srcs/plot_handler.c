/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:49:47 by mikim             #+#    #+#             */
/*   Updated: 2018/01/05 22:30:04 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	plot(t_env *e)
{
	int y;
	int d;
	int texture_y;
	int color;

	e->text_n = e->map.map[e->map_x][e->map_y] - 1;
	if (!e->side)
		wall_x = e->ray_pos_y + e->perp_wall_dist * e->ray_dir_y;
	else
		wall_x = e->ray_pos_x + e->perp_wall_dist * e->ray_dir_x;
	e->wall_x -= floor(wall_x);
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
