/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 18:08:22 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/17 17:00:11 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_init_struct(t_str *f_str)
{
	(*f_str).y1 = 0;
	(*f_str).y2 = 0;
	(*f_str).y3 = 0;
	(*f_str).y4 = 0;
	(*f_str).x1 = 0;
	(*f_str).x2 = 0;
	(*f_str).x3 = 0;
	(*f_str).x4 = 0;
	(*f_str).x1_save = 0;
	(*f_str).y1_save = 0;
	(*f_str).dim = 0;
	(*f_str).x_p = 0;
	(*f_str).y_p = 0;
	(*f_str).c = 'A';
	(*f_str).c_save = '#';
	(*f_str).final_nb = 5;
}

static void	ft_display_map(t_str *f_str, char **map_f)
{
	int i;

	i = 0;
	while (i < (*f_str).dim)
	{
		ft_putstr(map_f[i]);
		ft_putchar('\n');
		i++;
	}
}

static int	main_tetri_check(char *read, char ***map3d, int nb_map)
{
	char *map1d;

	map1d = (char *)malloc(sizeof(char) * ft_strlen(read) + 1);
	map1d[ft_strlen(read)] = '\0';
	stock_from_3d(map3d, map1d, nb_map);
	if (comp_map(map1d) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

static void	main_algo(int nb_map, char ***map3d)
{
	char		**map_f;
	int			***map_cord;
	t_str		f_str;

	ft_init_struct(&f_str);
	map_cord = alloc_map_cord(nb_map);
	stock_cord(map_cord, map3d, nb_map);
	search_dim(nb_map, &f_str);
	map_f = final_map(&f_str);
	while (f_str.final_nb)
	{
		f_str.final_nb = final(map_cord, map_f, nb_map, &f_str);
		if (f_str.final_nb == 2)
		{
			free(map_f);
			f_str.dim++;
			map_f = final_map(&f_str);
			f_str.c_save = '#';
		}
	}
	ft_display_map(&f_str, map_f);
}

int			main(int argc, char **argv)
{
	int					nb_map;
	char				***map3d;
	char				*read;

	read = (char *)malloc(sizeof(char) * 550);
	if (ft_read(argc, argv[1], read) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (ft_verif(read) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	nb_map = count_map(read);
	map3d = allocate_map(nb_map);
	create_map(read, map3d);
	place_hashes_start(map3d, nb_map);
	if (main_tetri_check(read, map3d, nb_map) != 1)
		return (0);
	main_algo(nb_map, map3d);
	return (0);
}
