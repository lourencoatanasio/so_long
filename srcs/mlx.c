/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:07:34 by ldiogo            #+#    #+#             */
/*   Updated: 2022/12/05 13:08:13 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_conv(void *mlx, t_tiles	*tiles)
{
	int	x;
	int	y;

	tiles->background = mlx_xpm_file_to_image(mlx, "./sprites/b.xpm", &x, &y);
	tiles->floor = mlx_xpm_file_to_image(mlx, "./sprites/chao.xpm", &x, &y);
	tiles->wall = mlx_xpm_file_to_image(mlx, "./sprites/parede.xpm", &x, &y);
	tiles->col = mlx_xpm_file_to_image(mlx, "./sprites/col.xpm", &x, &y);
	tiles->exit = mlx_xpm_file_to_image(mlx, "./sprites/saida2.xpm", &x, &y);
	tiles->player = mlx_xpm_file_to_image(mlx, "./sprites/chao2.xpm", &x, &y);
}

void	putsquare(t_general *gen)
{
	mlx_put_image_to_window(gen->mlx, gen->win, gen->tiles->background, 5, 11);
}

int	render(t_general *gen)
{
	putmap(gen);
	putsquare(gen);
	putstatus(gen);
	return (0);
}

void	controls(t_general *gen)
{
	mlx_key_hook(gen->win, keypress, gen);
	mlx_hook(gen->win, 17, 1L << 17, closewindow, gen);
}

void	loop(t_general *gen)
{
	controls(gen);
	mlx_loop_hook(gen->mlx, render, gen);
	mlx_loop(gen->mlx);
}
