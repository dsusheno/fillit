/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:04:59 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/17 17:16:08 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_str
{
	int				y1;
	int				y2;
	int				y3;
	int				y4;
	int				x1;
	int				x2;
	int				x3;
	int				x4;
	int				x1_save;
	int				y1_save;
	int				dim;
	int				x_p;
	int				y_p;
	int				final_nb;
	char			c;
	char			c_save;
}				t_str;

int				ft_read(int argc, char *name, char *read_entry);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
size_t			ft_strlen(const char *s);
int				check_nb_hashes(char *str);
int				count_map(char *str);
void			create_map(char *str, char ***map3d);
char			***allocate_map(int c_map);
void			place_hashes_start(char ***map, int c_map);
void			stock_from_3d(char ***map, char *map1d, int count_m);
int				comp_map(char *s2);
int				ft_verif(char *s);
int				***alloc_map_cord(int c_map);
void			stock_cord(int ***map_cord, char ***map3d, int c_map);
void			fill_dot(char **map_test, t_str *f_str);
void			search_dim(int c_map, t_str *f_str);
char			**final_map(t_str *f_str);
void			stock_save(t_str *f_str);
void			ft_fillit(char **map_f, t_str *f_str);
int				final(int ***map_cord, char **map_f,
		int c_map, t_str *f_str);
int				cord_ok(char **map_f, int ***map_cord,
		int nb_map, t_str *f_str);

#endif
