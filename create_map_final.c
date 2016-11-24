/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_final.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:14:40 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/16 15:47:41 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_sqrt(int nb)
{
	int minus;
	int i;

	minus = 1;
	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

void			search_dim(int c_map, t_str *f_str)
{
	(*f_str).dim = ft_sqrt(c_map * 4);
}

char			**final_map(t_str *f_str)
{
	char	**f_map;
	int		line;

	line = 0;
	f_map = malloc(sizeof(*f_map) * (*f_str).dim);
	while (line < (*f_str).dim)
	{
		f_map[line] = malloc(sizeof(**f_map) * ((*f_str).dim + 1));
		f_map[line][(*f_str).dim] = '\0';
		line++;
	}
	fill_dot(f_map, f_str);
	return (f_map);
}

void			fill_dot(char **map_test, t_str *f_str)
{
	int column;
	int line;

	column = 0;
	line = 0;
	while (line < (*f_str).dim)
	{
		while (column < (*f_str).dim)
		{
			map_test[line][column] = '.';
			column++;
		}
		column = 0;
		line++;
	}
}
