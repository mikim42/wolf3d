/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:40:27 by mikim             #+#    #+#             */
/*   Updated: 2018/01/09 09:39:04 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

bool	map_alloc(t_env *e)
{
	int i;

	if (!(e->map.map = ft_memalloc(sizeof(int*) * (e->map.row + 1))))
		return (false);
	i = -1;
	while (++i < e->map.row)
		if (!(e->map.map[i] = malloc(sizeof(int) * e->map.col)))
			return (false);
	return (true);
}

bool	map_create(t_env *e, int fd)
{
	char	**split;
	char	*line;
	int		ret;
	int		i;
	int		j;

	i = 0;
	if (!map_alloc(e))
		return (false);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (!(split = map_valid(e, line)))
			return (false);
		j = -1;
		while (++j < e->map.col)
			e->map.map[i][j] = ft_atoi(split[j]);
		ft_splitdel(split);
		free(line);
		i++;
	}
	if (ret == -1 || i != e->map.row)
		return (false);
	return (true);
}

bool	map_start_pos(t_env *e, int fd)
{
	char	**split;
	char	*line;
	bool	ret;

	ret = true;
	line = NULL;
	split = NULL;
	if (get_next_line(fd, &line) < 0)
		ret = false;
	if (!line || !(split = ft_strsplit(line, ' ')))
		ret = false;
	if (!split || !split[1] || split[2] ||
		(e->map.x = ft_atoi(split[0]) - 0.5) < 0 ||
		(e->map.y = ft_atoi(split[1]) - 0.5) < 0)
		ret = false;
	if (e->map.y >= e->map.row || e->map.x >= e->map.col)
		ret = false;
	if (line)
		free(line);
	if (split)
		ft_splitdel(split);
	return (ret);
}

bool	map_size(t_env *e, int fd)
{
	char	**split;
	char	*line;
	bool	ret;

	ret = true;
	line = NULL;
	split = NULL;
	if (get_next_line(fd, &line) < 0)
		ret = false;
	if (!line || !(split = ft_strsplit(line, ' ')))
		ret = false;
	if (!split || !split[1] || split[2] ||
		(e->map.col = ft_atoi(split[0])) < 2 ||
		(e->map.row = ft_atoi(split[1])) < 2)
		ret = false;
	if (line)
		free(line);
	if (split)
		ft_splitdel(split);
	return (ret);
}
