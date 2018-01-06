/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:16:43 by mikim             #+#    #+#             */
/*   Updated: 2018/01/06 13:14:36 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	init_wolf3d(t_env *e)
{
	int i;

	e->dir_x = -1;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = 0.66;
	e->curr_t = 0;
	e->prev_t = 0;
	e->mlx.wid = DEFAULT;
	e->mlx.hgt = DEFAULT;
	e->mlx.mlx = mlx_init();
	pthread_mutex_init(&e->mutex, NULL);
	i = -1;
	while (++i < 8)
		if (!(e->texture[i] = malloc(sizeof(unsigned int) * FT_SQR(TEXTURE))))
			ft_exit(e, "wolf3d: failed to init mlx");
}

void	init_map(t_env *e, char *map)
{
	int fd;

	if (!(fd = open(map, O_RDONLY)))
		ft_exit(e, "wolf3d: map error");
	if (!map_size(e, fd))
		ft_exit(e, "wolf3d: wrong map size");
	if (!map_start_pos(e, fd))
		ft_exit(e, "wolf3d: wrong start position");
	if (!map_create(e, fd))
		ft_exit(e, "wolf3d: failed to create map");
}

void	init_texture(t_env *e)
{
	int xor_color;
	int y_color;
	int xy_color;
	int x;
	int y;

	y = -1;
	while (++y < TEXTURE)
	{
		x = -1;
		while (++x < TEXTURE)
		{
			xor_color = (x * 256 / TEXTURE) ^ (y * 256 / TEXTURE);
			y_color = y * 256 / TEXTURE;
			xy_color = y * 128 / TEXTURE + x * 128 / TEXTURE;
			e->texture[0][TEXTURE * y + x] =
			65536 * 254 * (x != y && x != TEXTURE - y);
			e->texture[1][TEXTURE * y + x] =
			xy_color + 256 * xy_color + 65536 * xy_color;
			e->texture[2][TEXTURE * y + x] = 256 * xy_color + 65536 * xy_color;
			e->texture[3][TEXTURE * y + x] =
			xor_color + 256 * xor_color + 65536 * xor_color;
			e->texture[4][TEXTURE * y + x] = 256 * xor_color;
			e->texture[5][TEXTURE * y + x] = 65536 * 192 * (x % 16 && y & 16);
		}
	}
}

void	init_mlx(t_env *e)
{
	int i;

	e->mlx.win = mlx_new_window(e->mlx.mlx, e->mlx.wid, e->mlx.hgt,
	"Wolf3d .mikim");
	e->mlx.img = mlx_new_image(e->mlx.mlx, e->mlx.wid, e->mlx.hgt);
	e->mlx.data = (int*)mlx_get_data_addr(&e->mlx.img, &e->mlx.bits,
	&e->mlx.size, &e->mlx.endian);
	i = -1;
}

void	parse(t_env *e, char *map)
{
	init_mlx(e);
	init_texture(e);
	init_map(e, map);
	init_wolf3d(e);
}
