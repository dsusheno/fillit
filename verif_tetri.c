/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:19:30 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/16 15:04:29 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	min_x(char **map)
{
	int y;
	int x_min;
	int x;

	y = 0;
	x = 0;
	x_min = 4;
	while (y < 4)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '#' && x < x_min)
				x_min = x;
			x++;
		}
		y++;
		x = 0;
	}
	return (x_min);
}

static int	min_y(char **map)
{
	int y;
	int y_min;
	int x;

	y = 0;
	x = 0;
	y_min = 4;
	while (y < 4)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '#' && y < y_min)
				y_min = y;
			x++;
		}
		y++;
		x = 0;
	}
	return (y_min);
}

static void	place_hashes_centre(char ***map, int nb_m)
{
	static int	a;
	static int	b;
	static int	x;
	static int	y;

	a = min_x(map[nb_m]);
	b = min_y(map[nb_m]);
	while (y < 4)
	{
		while (map[nb_m][y][x])
		{
			if (map[nb_m][y][x] == '#')
			{
				map[nb_m][y][x] = '.';
				map[nb_m][y - b][x - a] = '#';
			}
			x++;
		}
		y++;
		x = 0;
	}
	y = 0;
}

void		place_hashes_start(char ***map, int c_map)
{
	static int	nb_m;

	while (nb_m < c_map)
	{
		place_hashes_centre(map, nb_m);
		nb_m++;
	}
}

void		stock_from_3d(char ***map, char *map1d, int count_m)
{
	static int	x;
	static int	y;
	static int	nb_m;
	static int	i;

	while (nb_m < count_m)
	{
		while (y < 4)
		{
			while (map[nb_m][y][x])
			{
				map1d[i] = map[nb_m][y][x];
				i++;
				x++;
			}
			map1d[i] = '\n';
			i++;
			x = 0;
			y++;
		}
		map1d[i] = '\n';
		i++;
		y = 0;
		nb_m++;
	}
}
