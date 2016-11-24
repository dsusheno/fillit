/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 20:27:38 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/16 16:17:28 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		cord_ok(char **map_f, int ***map_cord, int nb_map, t_str *f_str)
{
	(*f_str).y1 = map_cord[nb_map][0][0];
	(*f_str).x1 = map_cord[nb_map][0][1];
	(*f_str).y2 = map_cord[nb_map][1][0];
	(*f_str).x2 = map_cord[nb_map][1][1];
	(*f_str).y3 = map_cord[nb_map][2][0];
	(*f_str).x3 = map_cord[nb_map][2][1];
	(*f_str).y4 = map_cord[nb_map][3][0];
	(*f_str).x4 = map_cord[nb_map][3][1];
	if ((*f_str).y4 + (*f_str).y_p >= (*f_str).dim)
		return (0);
	if ((map_f[(*f_str).y1 + (*f_str).y_p][(*f_str).x1 + (*f_str).x_p] != '.' ||
		map_f[(*f_str).y2 + (*f_str).y_p][(*f_str).x2 + (*f_str).x_p] != '.' ||
		map_f[(*f_str).y3 + (*f_str).y_p][(*f_str).x3 + (*f_str).x_p] != '.' ||
		(((((*f_str).x1_save >= (*f_str).x1 + (*f_str).x_p
		&& (*f_str).y1_save >= (*f_str).y1 + (*f_str).y_p)
		|| (*f_str).y1_save > (*f_str).y1 + (*f_str).y_p))
		&& (*f_str).c == (*f_str).c_save) ||
		map_f[(*f_str).y4 + (*f_str).y_p][(*f_str).x4 + (*f_str).x_p] != '.'))
		return (1);
	return (0);
}

void	stock_save(t_str *f_str)
{
	(*f_str).x1_save = (*f_str).x1 + (*f_str).x_p;
	(*f_str).y1_save = (*f_str).y1 + (*f_str).y_p;
}

void	ft_fillit(char **map_f, t_str *f_str)
{
	map_f[(*f_str).y1 + (*f_str).y_p][(*f_str).x1 + (*f_str).x_p] = (*f_str).c;
	map_f[(*f_str).y2 + (*f_str).y_p][(*f_str).x2 + (*f_str).x_p] = (*f_str).c;
	map_f[(*f_str).y3 + (*f_str).y_p][(*f_str).x3 + (*f_str).x_p] = (*f_str).c;
	map_f[(*f_str).y4 + (*f_str).y_p][(*f_str).x4 + (*f_str).x_p] = (*f_str).c;
}
