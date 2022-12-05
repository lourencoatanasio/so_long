/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:35:45 by ldiogo            #+#    #+#             */
/*   Updated: 2022/12/05 14:35:47 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <ctype.h>
# include <string.h>
# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"

# define MS	50

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_player
{
	int			x;
	int			y;
	int			collectibles;
	int			steps;
}				t_player;

typedef struct s_tiles
{
	t_img		*floor;
	t_img		*wall;
	t_img		*col;
	t_img		*exit;
	t_img		*player;
	t_img		*background;
}				t_tiles;

typedef struct s_spots
{
	int			i;
	int			j;
	int			p;
	int			e;
	int			c;
}				t_spots;

typedef struct s_values
{
	int		i;
	int		j;
	int		x;
	int		y;
}				t_values;

typedef struct s_general
{
	t_tiles		*tiles;
	t_player	*player;
	int			col;
	char		**map;
	void		*mlx;
	void		*win;
}				t_general;

char	*ft_strrev(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void	readmap(t_general *gen, char *file);
int		numberoflines(char *file);
void	freemap(char **map);
void	end(t_general *gen);
int		closewindow(void);
void	checkmap(t_general *gen);
t_spots	fillspots(void);
void	mapchecker(t_general *gen);
void	sizechecker(t_general *gen);
void	wallchecker(t_general *gen, char *file);
void	checkmapvalid(t_general *gen, char *file);
void	xpm_conv(void *mlx, t_tiles *tiles);
void	putmap(t_general *gen);
void	putsquare(t_general *gen);
void	putstatus(t_general *gen);
int		render(t_general *gen);
void	moveplayer(t_general *gen, t_values v);
void	playerpos(t_general *gen);
int		keypress(int keycode, t_general *gen);
int		colecount(char **map);
void	controls(t_general *gen);
void	loop(t_general *gen);
void	puttile(t_general *gen, char tile, int x, int y);
void	firstfree(t_general *gen);
void	flags(int ac, char **av);

#endif //SO_LONG_H
