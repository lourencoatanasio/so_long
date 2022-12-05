/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:29:12 by ldiogo            #+#    #+#             */
/*   Updated: 2022/12/05 14:29:13 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_general	*gen;

	flags(ac, av);
	gen = (t_general *)malloc(sizeof(t_general));
	gen->player = (t_player *)malloc(sizeof(t_player));
	gen->player->collectibles = 0;
	gen->player->steps = 0;
	gen->player->x = 0;
	gen->player->y = 0;
	gen->map = (char **)malloc(sizeof(char *) * (numberoflines(av[1]) + 1));
	readmap(gen, av[1]);
	checkmapvalid(gen, av[1]);
	gen->col = colecount(gen->map);
	gen->mlx = mlx_init();
	gen->tiles = (t_tiles *)malloc(sizeof(t_tiles));
	xpm_conv(gen->mlx, gen->tiles);
	gen->win = mlx_new_window(gen->mlx, MS * (strlen(gen->map[0]) - 1),
			MS * numberoflines(av[1]), "so_long");
	loop(gen);
	return (0);
}
