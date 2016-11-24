/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:25:58 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/16 15:02:12 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_nb_hashes(char *str)
{
	int	i;
	int	hashes;

	i = 0;
	hashes = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hashes++;
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			if (hashes != 4)
				return (0);
			hashes = 0;
			i++;
		}
		if (hashes > 4)
			return (0);
		i++;
	}
	return (1);
}

int		count_map(char *str)
{
	int	i;
	int	map;

	i = 0;
	map = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			map++;
		i++;
	}
	return (map);
}

char	***allocate_map(int c_map)
{
	char	***map3d;
	int		line;
	int		nb_map;

	nb_map = 0;
	line = 0;
	map3d = malloc(sizeof(*map3d) * (c_map + 1));
	while (nb_map < c_map + 1)
	{
		map3d[nb_map] = malloc(sizeof(**map3d) * 4);
		while (line < 4)
		{
			map3d[nb_map][line] = malloc(sizeof(***map3d) * 5);
			line++;
		}
		line = 0;
		nb_map++;
	}
	return (map3d);
}

void	create_map(char *str, char ***map3d)
{
	static int	i;
	static int	line;
	static int	column;
	static int	nb_map;

	while (str[i])
	{
		map3d[nb_map][line][column] = str[i];
		if (str[i] == '\n' && str[i + 1] != '\n' && str[i + 1] != '\0')
		{
			map3d[nb_map][line][column] = '\0';
			line++;
			column = -1;
		}
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			map3d[nb_map][line][column] = '\0';
			nb_map++;
			line = 0;
			column = -1;
			i++;
		}
		column++;
		i++;
	}
}
