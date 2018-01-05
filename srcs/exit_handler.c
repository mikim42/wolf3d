/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:12:44 by mikim             #+#    #+#             */
/*   Updated: 2018/01/04 22:50:13 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	destroy(t_env *e)
{
	int i;

	i = -1;
	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	if (e->win)
		mlx_destroy_window(e-mlx, e->win);
	if (e->map->map)
		while (++i < e->map->row)
			free(e->map->map[i]);
}

void	ft_exit(t_env *e, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	destory(e);
	exit(0);
}
