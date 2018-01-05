/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:40:27 by mikim             #+#    #+#             */
/*   Updated: 2018/01/04 22:45:13 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	parse_map(t_env *e, char *map)
{
	int fd;

	if (!(fd = open(map, O_RDONLY)))
		ft_exit(e, "wolf3d: map error");
}
