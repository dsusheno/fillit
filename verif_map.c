/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:17:22 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/17 15:09:17 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_verif_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '#' && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_verif_line(char *s, int *i, int *nb_col, int *nb_line)
{
	if (s[*i] == '\n' && s[*i + 1] != '\n' && s[*i + 1] != '\0')
	{
		(*nb_line)++;
		if ((*nb_col / 5) != *nb_line || (*nb_col % 5) != 0)
			return (0);
	}
	return (1);
}

static int	ft_verif_endline(char *s, int *i, int *nb_col, int *nb_line)
{
	if (s[*i] == '\n' && s[*i + 1] == '\n')
	{
		(*nb_line)++;
		if (*nb_line != 4)
			return (0);
		if ((*nb_col / 5) != *nb_line || (*nb_col % 5) != 0)
			return (0);
		(*i)++;
		*nb_col = 0;
		*nb_line = 0;
	}
	return (1);
}

static int	ft_verif_endmap(char *s, int *i, int *nb_col, int *nb_line)
{
	if (s[*i] == '\n' && s[*i + 1] == '\0')
	{
		(*nb_line)++;
		if (*nb_line != 4)
			return (0);
		if ((*nb_col / 5) != *nb_line || (*nb_col % 5) != 0)
			return (0);
	}
	return (1);
}

int			ft_verif(char *s)
{
	int nb_col;
	int nb_line;
	int	i;

	nb_col = 1;
	nb_line = 0;
	i = 0;
	if (ft_verif_char(s) != 1)
		return (0);
	while (s[i])
	{
		if (s[i] != '\n' && s[i + 1] == '\0')
			return (0);
		if (ft_verif_line(s, &i, &nb_col, &nb_line) == 0)
			return (0);
		if (ft_verif_endline(s, &i, &nb_col, &nb_line) == 0)
			return (0);
		if (ft_verif_endmap(s, &i, &nb_col, &nb_line) == 0)
			return (0);
		i++;
		nb_col++;
	}
	if (check_nb_hashes(s) != 1)
		return (0);
	return (1);
}
