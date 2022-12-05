/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:07:42 by ldiogo            #+#    #+#             */
/*   Updated: 2022/12/05 14:07:43 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_general *gen)
{
	if (keycode == 65307)
		end(gen);
	if (keycode == 119)
	{
		gen->player->y -= 1;
		playerpos(gen);
	}
	if (keycode == 115)
	{
		gen->player->y += 1;
		playerpos(gen);
	}
	if (keycode == 97)
	{
		gen->player->x -= 1;
		playerpos(gen);
	}
	if (keycode == 100)
	{
		gen->player->x += 1;
		playerpos(gen);
	}
	return (0);
}

void	playerpos(t_general *gen)
{
	t_values	val;
	int			i;
	int			j;

	i = 0;
	while (gen->map[i])
	{
		j = 0;
		while (gen->map[i][j])
		{
			if (gen->map[i][j] == 'P')
			{
				break ;
			}
			j++;
		}
		if (gen->map[i][j] == 'P')
			break ;
		i++;
	}
	val.i = i;
	val.j = j;
	val.x = gen->player->x;
	val.y = gen->player->y;
	moveplayer (gen, val);
}

void	moveplayer(t_general *gen, t_values v)
{
	if (gen->map[v.i + v.y][v.j + v.x] == '0'
		|| gen->map[v.i + v.y][v.j + v.x] == 'C')
	{
		if (gen->map[v.i + v.y][v.j + v.x] == 'C')
			gen->player->collectibles++;
		gen->map[v.i + v.y][v.j + v.x] = 'P';
		gen->map[v.i][v.j] = '0';
		gen->player->steps++;
	}
	if (gen->map[v.i + v.y][v.j + v.x] == 'E')
	{
		if (gen->player->collectibles == gen->col)
		{
			printf("You win!\n");
			end(gen);
		}
		else
			printf("You need to collect all the collectibles\n");
	}
	gen->player->y = 0;
	gen->player->x = 0;
}
