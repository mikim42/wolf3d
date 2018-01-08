/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:16:43 by mikim             #+#    #+#             */
/*   Updated: 2018/01/07 17:25:24 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

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
	if (!map_valid_wall(e))
		ft_exit(e, "wolf3d: invalid map");
}

void	init_texture(t_env *e)
{
	int xor_color;
	int y_color;
	int xy_color;
	int x;
	int y;

	x = -1;
	while (++x < TEXTURE)
	{
		y = -1;
		while (++y < TEXTURE)
		{
			xor_color = (x * 256 / TEXTURE) ^ (y * 256 / TEXTURE);
			y_color = y * 256 / TEXTURE;
			xy_color = y * 128 / TEXTURE + x * 128 / TEXTURE;
			e->texture[0][TEXTURE * y + x] = TEXTURE_0;
			e->texture[1][TEXTURE * y + x] = TEXTURE_1;
			e->texture[2][TEXTURE * y + x] = TEXTURE_2;
			e->texture[3][TEXTURE * y + x] = TEXTURE_3;
			e->texture[4][TEXTURE * y + x] = TEXTURE_4;
			e->texture[5][TEXTURE * y + x] = TEXTURE_5;
		}
	}
}

void	init_mlx(t_env *e)
{
	e->mlx.img = mlx_new_image(e->mlx.mlx, WINDOW, WINDOW);
	e->mlx.data = (int*)mlx_get_data_addr(e->mlx.img, &e->mlx.bits,
	&e->mlx.size, &e->mlx.endian);
}

void	init_wolf3d(t_env *e)
{
	int i;

	e->dir_x = -1.0;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = 0.66;
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WINDOW, WINDOW,
	"Wolf3d .mikim");
	i = -1;
	while (++i < 6)
		if (!(e->texture[i] = malloc(sizeof(int) * FT_SQR(TEXTURE))))
			ft_exit(e, "wolf3d: failed to init mlx");
}

void	parse(t_env *e, char *map)
{
	init_wolf3d(e);
	init_mlx(e);
	init_texture(e);
	init_map(e, map);
}
