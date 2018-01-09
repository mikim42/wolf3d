/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:59:08 by mikim             #+#    #+#             */
/*   Updated: 2018/01/09 09:38:52 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	dda_loop(t_env *e)
{
	while (true)
	{
		if (e->side_dist_x < e->side_dist_y)
		{
			e->side_dist_x += e->delta_dist_x;
			e->map_x += e->step_x;
			e->side = 0;
		}
		else
		{
			e->side_dist_y += e->delta_dist_y;
			e->map_y += e->step_y;
			e->side = 1;
		}
		if (e->map.map[e->map_x][e->map_y] > 0)
			break ;
	}
	if (!e->side)
		e->perp_wall_dist =
		(e->map_x - e->ray_pos_x + (1 - e->step_x) / 2) / e->ray_dir_x;
	else
		e->perp_wall_dist =
		(e->map_y - e->ray_pos_y + (1 - e->step_y) / 2) / e->ray_dir_y;
}

void	dda_algorithm(t_env *e)
{
	e->delta_dist_x = sqrt(1 + FT_SQR(e->ray_dir_y) / FT_SQR(e->ray_dir_x));
	e->delta_dist_y = sqrt(1 + FT_SQR(e->ray_dir_x) / FT_SQR(e->ray_dir_y));
	if (e->ray_dir_x < 0)
	{
		e->step_x = -1;
		e->side_dist_x = (e->ray_pos_x - e->map_x) * e->delta_dist_x;
	}
	else
	{
		e->step_x = 1;
		e->side_dist_x = (e->map_x + 1.0 - e->ray_pos_x) * e->delta_dist_x;
	}
	if (e->ray_dir_y < 0)
	{
		e->step_y = -1;
		e->side_dist_y = (e->ray_pos_y - e->map_y) * e->delta_dist_y;
	}
	else
	{
		e->step_y = 1;
		e->side_dist_y = (e->map_y + 1.0 - e->ray_pos_y) * e->delta_dist_y;
	}
}

void	calc_ray(t_env *e, int x)
{
	e->camera = 2 * x / (double)WINDOW - 1;
	e->ray_pos_x = e->map.x;
	e->ray_pos_y = e->map.y;
	e->map_x = (int)e->map.x;
	e->map_y = (int)e->map.y;
	e->ray_dir_x = e->dir_x + e->plane_x * e->camera;
	e->ray_dir_y = e->dir_y + e->plane_y * e->camera;
}

void	raycasting(t_env *e)
{
	int x;
	int	st;
	int end;

	x = -1;
	while (++x < WINDOW)
	{
		calc_ray(e, x);
		dda_algorithm(e);
		dda_loop(e);
		e->line_hgt = (int)(WINDOW / e->perp_wall_dist);
		st = -e->line_hgt / 2 + WINDOW / 2;
		end = e->line_hgt / 2 + WINDOW / 2;
		if (st < 0)
			st = 0;
		if (end >= WINDOW)
			end = WINDOW - 1;
		plot(e, x, st, end);
		plot_floor(e, x, end);
	}
}
