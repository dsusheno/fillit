/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_cord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:07:27 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/16 15:04:01 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			***alloc_map_cord(int c_map)
{
	int	***map_cord;
	int nb_map;
	int tetri;

	nb_map = 0;
	tetri = 0;
	map_cord = malloc(sizeof(*map_cord) * c_map);
	while (nb_map < c_map + 1)
	{
		map_cord[nb_map] = malloc(sizeof(**map_cord) * 4);
		while (tetri < 4)
		{
			map_cord[nb_map][tetri] = malloc(sizeof(***map_cord) * 2);
			tetri++;
		}
		tetri = 0;
		nb_map++;
	}
	return (map_cord);
}

static void	stock_cord_centre(int ***map_cord, char ***map3d, int nb_map)
{
	static int	x;
	static int	y;
	static int	line;

	while (y < 4)
	{
		while (x < 4)
		{
			if (map3d[nb_map][y][x] == '#')
			{
				map_cord[nb_map][line][0] = y;
				map_cord[nb_map][line][1] = x;
				line++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	line = 0;
	y = 0;
}

void		stock_cord(int ***map_cord, char ***map3d, int c_map)
{
	static int	nb_map;

	while (nb_map < c_map + 1)
	{
		stock_cord_centre(map_cord, map3d, nb_map);
		nb_map++;
	}
}
