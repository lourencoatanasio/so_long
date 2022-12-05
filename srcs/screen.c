/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:57:45 by ldiogo            #+#    #+#             */
/*   Updated: 2022/12/05 13:57:46 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	colecount(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_spots	fillspots(void)
{
	t_spots	spots;

	spots.i = 0;
	spots.j = 0;
	spots.p = 0;
	spots.e = 0;
	spots.c = 0;
	return (spots);
}

void	puttile(t_general *gen, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(gen->mlx, gen->win, gen->tiles->wall, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(gen->mlx, gen->win, gen->tiles->floor, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(gen->mlx, gen->win, gen->tiles->col, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(gen->mlx, gen->win, gen->tiles->exit, x, y);
	else
		mlx_put_image_to_window(gen->mlx, gen->win, gen->tiles->player, x, y);
}

void	putmap(t_general *gen)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (gen->map[++i])
	{
		j = -1;
		while (gen->map[i][++j])
		{
			puttile(gen, gen->map[i][j], x, y);
			x += MS;
		}
		x = 0;
		y += MS;
	}
}

void	putstatus(t_general *gen)
{
	char	*str2;
	char	*str;
	char	*res;

	str = ft_itoa(gen->player->collectibles);
	str2 = ft_strjoin("Collected : ", str);
	free(str);
	str = ft_strjoin(str2, " / ");
	free(str2);
	str2 = ft_itoa(gen->col);
	res = ft_strjoin(str, str2);
	free(str);
	free(str2);
	str = ft_strjoin(res, "    |    Moves : ");
	free(res);
	str2 = ft_itoa(gen->player->steps);
	res = ft_strjoin(str, str2);
	free(str);
	free(str2);
	mlx_string_put(gen->mlx, gen->win, 10, 25, 0x00FF0000, res);
	free(res);
}
