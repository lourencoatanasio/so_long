/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:21:23 by ldiogo            #+#    #+#             */
/*   Updated: 2022/12/05 14:21:24 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flags(int ac, char **av)
{
	int		fd;
	char	*temp;

	temp = ft_strjoin("./maps/", av[1]);
	fd = open(temp, O_RDONLY);
	free(temp);
	if (ac != 2)
	{
		write(1, "0.1 Error", 9);
		exit(1);
	}
	if (fd == -1)
	{
		write(1, "0.2 Error", 9);
		exit(1);
	}
	return ;
}

void	firstfree(t_general *gen)
{
	freemap(gen->map);
	free(gen->player);
	free(gen);
	exit(0);
}

void	freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	end(t_general *gen)
{
	mlx_destroy_window(gen->mlx, gen->win);
	mlx_destroy_image(gen->mlx, gen->tiles->floor);
	mlx_destroy_image(gen->mlx, gen->tiles->wall);
	mlx_destroy_image(gen->mlx, gen->tiles->col);
	mlx_destroy_image(gen->mlx, gen->tiles->exit);
	mlx_destroy_image(gen->mlx, gen->tiles->player);
	mlx_destroy_image(gen->mlx, gen->tiles->background);
	mlx_destroy_display(gen->mlx);
	freemap(gen->map);
	free(gen->tiles);
	free(gen->player);
	free(gen->mlx);
	free(gen);
	exit(0);
}

int	closewindow(void)
{
	end(0);
	return (0);
}
