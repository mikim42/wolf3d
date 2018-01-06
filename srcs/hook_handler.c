/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:52:07 by mikim             #+#    #+#             */
/*   Updated: 2018/01/06 13:29:33 by mikim            ###   ########.fr       */
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
	if (e->mlx.motion)
	{
		e->mlx.motion_x = x;
		e->mlx.motion_y = y;
		wolf3d(e);
	}
	return (0);
}

int		mouse_hooks(int button, int x, int y, t_env *e)
{
	button = x + y + (int)e;
	return (0);
}

int		key_hooks(int code, t_env *e)
{
	code = (int)e;
	return (0);
}
