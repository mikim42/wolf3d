/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:31:11 by mikim             #+#    #+#             */
/*   Updated: 2018/01/18 15:40:37 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

bool	map_valid_wall(t_env *e)
{
	int x;
	int y;

	y = -1;
	if (e->map.map[(int)e->map.x][(int)e->map.y] != 0)
		return (false);
	while (++y < e->map.row)
	{
		x = -1;
		while (++x < e->map.col)
		{
			if ((y == 0 || y == e->map.row - 1) && e->map.map[y][x] < 1)
				return (false);
			if ((x == 0 || x == e->map.col - 1) && e->map.map[y][x] < 1)
				return (false);
		}
	}
	return (true);
}

char	**map_valid(t_env *e, char *line, int index)
{
	char	**split;
	int		i;

	i = -1;
	while (line[++i])
		if (!(FT_ISNUM(line[i]) || line[i] == ' ') || index >= e->map.row)
		{
			free(line);
			return (NULL);
		}
	if (!(split = ft_strsplit(line, ' ')))
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (split[++i])
		;
	if (i != e->map.col)
	{
		free(line);
		ft_splitdel(split);
		return (NULL);
	}
	return (split);
}
