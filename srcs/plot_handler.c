/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:49:47 by mikim             #+#    #+#             */
/*   Updated: 2018/01/09 09:39:24 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	calc_ray_floor(t_env *e)
{
	if (!e->side && e->ray_dir_x > 0)
	{
		e->floor_x = e->map_x;
		e->floor_y = e->map_y + e->wall_x;
	}
	else if (!e->side && e->ray_dir_x < 0)
	{
		e->floor_x = e->map_x + 1.0;
		e->floor_y = e->map_y + e->wall_x;
	}
	else if (e->side && e->ray_dir_y > 0)
	{
		e->floor_x = e->map_x + e->wall_x;
		e->floor_y = e->map_y;
	}
	else
	{
		e->floor_x = e->map_x + e->wall_x;
		e->floor_y = e->map_y + 1.0;
	}
}

void	plot_floor(t_env *e, int x, int end)
{
	int y;

	calc_ray_floor(e);
	e->dist_wall = e->perp_wall_dist;
	e->dist_pos = 0;
	y = end + 1;
	while (++y < WINDOW)
	{
		e->dist_curr = WINDOW / (2.0 * y - WINDOW);
		e->weight = (e->dist_curr - e->dist_pos) / (e->dist_wall - e->dist_pos);
		e->curr_floor_x = e->weight * e->floor_x + (1.0 - e->weight) * e->map.x;
		e->curr_floor_y = e->weight * e->floor_y + (1.0 - e->weight) * e->map.y;
		e->floor_text_x = (int)(e->curr_floor_x * TEXTURE) % TEXTURE;
		e->floor_text_y = (int)(e->curr_floor_y * TEXTURE) % TEXTURE;
		e->mlx.data[x + (y * e->mlx.size) / 4] = (e->texture[4]
		[TEXTURE * e->floor_text_y + e->floor_text_x] >> 1) & 8355711;
		e->mlx.data[x + ((WINDOW - y) * e->mlx.size) / 4] =
		e->texture[5][TEXTURE * e->floor_text_y + e->floor_text_x];
	}
}

int		get_wall(t_env *e)
{
	int wall;

	if (e->side)
	{
		if (e->map.y < e->map_y)
			wall = 2;
		else
			wall = 3;
	}
	else
	{
		if (e->map.x < e->map_x)
			wall = 1;
		else
			wall = 0;
	}
	return (wall);
}

void	plot(t_env *e, int x, int st, int end)
{
	int d;
	int texture_x;
	int texture_y;
	int color;
	int	wall;

	wall = get_wall(e);
	if (!e->side)
		e->wall_x = e->ray_pos_y + e->perp_wall_dist * e->ray_dir_y;
	else
		e->wall_x = e->ray_pos_x + e->perp_wall_dist * e->ray_dir_x;
	e->wall_x -= floor(e->wall_x);
	texture_x = e->wall_x * TEXTURE;
	if ((!e->side && e->ray_dir_x > 0) || (e->side && e->ray_dir_y < 0))
		texture_x = TEXTURE - texture_x - 1;
	while (st < end)
	{
		d = st * 256 - WINDOW * 128 + e->line_hgt * 128;
		texture_y = ((d * TEXTURE) / e->line_hgt) / 256;
		color = e->texture[wall][TEXTURE * texture_y + texture_x];
		if (e->side)
			color = (color >> 1) & 8355711;
		e->mlx.data[x + (st++ * e->mlx.size) / 4] = color;
	}
}
