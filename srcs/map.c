/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:16:21 by ldiogo            #+#    #+#             */
/*   Updated: 2022/12/05 13:16:22 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkmap(t_general *gen)
{
	int	i;
	int	j;

	i = 0;
	while (gen->map[i])
	{
		j = 0;
		while (gen->map[i][j])
		{
			if (gen->map[i][j] != '1' && gen->map[i][j] !=
				'0' && gen->map[i][j] != 'C' &&
				gen->map[i][j] != 'E' && gen->map[i][j] !=
				'P' && gen->map[i][j] != '\n')
			{
				write(1, "1 Error - Map is not valid", 26);
				firstfree(gen);
			}
			j++;
		}
		i++;
	}
}

void	mapchecker(t_general *gen)
{
	t_spots	spots;

	spots = fillspots();
	while (gen->map[spots.i])
	{
		spots.j = 0;
		while (gen->map[spots.i][spots.j])
		{
			if (gen->map[spots.i][spots.j] == 'P')
				spots.p++;
			if (gen->map[spots.i][spots.j] == 'E')
				spots.e++;
			if (gen->map[spots.i][spots.j] == 'C')
				spots.c++;
			spots.j++;
		}
		spots.i++;
	}
	if (spots.p != 1 || spots.e != 1 || spots.c == 0)
	{
		write(1, "2 Error - Map is not valid", 26);
		firstfree(gen);
	}
}

void	sizechecker(t_general *gen)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (gen->map[i])
	{
		j = 0;
		while (gen->map[i][j])
		{
			j++;
		}
		if (k == 0)
			k = j;
		if (k != j)
		{
			write(1, "3 Error - Map is not valid", 26);
			firstfree(gen);
		}
		i++;
	}
}

void	wallchecker(t_general *gen, char *file)
{
	int	i;
	int	j;

	i = 0;
	while (gen->map[i])
	{
		j = 0;
		while (gen->map[i][j] && j < ft_strlen(gen->map[i]) - 1)
		{
			if (i == 0 || j == 0 || i == numberoflines(file) - 1
				|| j == ft_strlen(gen->map[i]) - 2)
			{
				if (gen->map[i][j] != '1')
				{
					write(1, "4 Error - Map is not valid", 26);
					firstfree(gen);
					exit(0);
				}
			}
			j++;
		}
		i++;
	}
}

void	readmap(t_general *gen, char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	temp = ft_strjoin("./maps/", file);
	fd = open(temp, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		free(temp);
		firstfree(gen);
	}
	line = get_next_line(fd);
	while (line)
	{
		gen->map[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	gen->map[i] = NULL;
	free(temp);
	close(fd);
}
