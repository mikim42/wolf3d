/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:12:44 by mikim             #+#    #+#             */
/*   Updated: 2018/01/09 03:44:05 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	destroy(t_env *e)
{
	int i;

	if (e->mlx.img)
		mlx_destroy_image(e->mlx.mlx, e->mlx.img);
	if (e->mlx.win)
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	if (e->map.map)
	{
		i = -1;
		while (e->map.map[++i])
			free(e->map.map[i]);
		free(e->map.map);
	}
	if (e->texture[0])
	{
		i = -1;
		while (++i < 4)
			free(e->texture[i]);
	}
}

void	ft_exit(t_env *e, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	system("killall afplay");
	destroy(e);
	exit(0);
}
