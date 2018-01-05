/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:32:52 by mikim             #+#    #+#             */
/*   Updated: 2018/01/04 22:49:26 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int main(int ac, char **av)
{
	t_env e;

	ft_bzero(&e, sizeof(e));
	if (ac == 2)
	{
		parse(&e, av[1]);
		wolf3d(&e);
	}
	else if (ac == 1)
		ft_exit(&e, "no map");
	else
		ft_exit(&e, "wolf3d: illegal option");
	return (0);
}
