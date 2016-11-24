/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:26:03 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/16 15:46:01 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	replace_save(char **map_f, t_str *f_str, int k)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (i < (*f_str).dim)
	{
		while (map_f[i][c] != '\0')
		{
			if (map_f[i][c] == (*f_str).c_save)
			{
				if (k == 0)
				{
					(*f_str).x1_save = c;
					(*f_str).y1_save = i;
					k++;
				}
				map_f[i][c] = '.';
			}
			c++;
		}
		i++;
		c = 0;
	}
}

static void	final_header(char **map_f, t_str *f_str)
{
	int k;

	k = 0;
	(*f_str).y_p = 0;
	(*f_str).x_p = 0;
	(*f_str).c_save = (*f_str).c - 1;
	replace_save(map_f, f_str, k);
}

static void	final_down(char **map_f, t_str *f_str)
{
	ft_fillit(map_f, f_str);
	stock_save(f_str);
	(*f_str).c++;
	(*f_str).x_p = 0;
	(*f_str).y_p = 0;
}

static void	f_c(char **map_f, int ***map_cord, int nb_map, t_str *f_str)
{
	while (cord_ok(map_f, map_cord, nb_map, f_str) == 1)
	{
		if ((*f_str).x2 + (*f_str).x_p < (*f_str).dim + 1)
			(*f_str).x_p++;
		else
		{
			(*f_str).x_p = 0;
			(*f_str).y_p++;
		}
	}
}

int			final(int ***map_cord, char **map_f, int c_map, t_str *f_str)
{
	static	int	nb_map;

	final_header(map_f, f_str);
	if (nb_map != 0)
	{
		nb_map--;
		(*f_str).c = (*f_str).c_save;
	}
	while (nb_map < c_map)
	{
		f_c(map_f, map_cord, nb_map, f_str);
		if ((*f_str).y_p + (*f_str).y4 >= (*f_str).dim)
		{
			if ((*f_str).c == 'A')
				return (2);
			return (1);
		}
		final_down(map_f, f_str);
		nb_map++;
	}
	return (0);
}
