/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:52:07 by mikim             #+#    #+#             */
/*   Updated: 2018/01/05 17:54:42 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		close_hooks(t_env *e)
{
	ft_exit(e, NULL);
	return (0);
}

int		expose_hooks(t_env *e)
{
	if (e->mlx.expose)
		wolf3d(e);
	else
		e->mlx.expose = 1;
	return (0);
}

int		motion_hooks(int x, int y, t_env *e)
{
	if (e->motion)
	{
		e->mlx.motion_x = x;
		e->mlx.motion_y = y;
		wolf3d(e);
	}
	return (0);
}

int		mouse_hooks(int button, int x, int y, t_env *e)
{
	return (0);
}

int		key_hooks(int code, t_env *e)
{
	return (0);
}
