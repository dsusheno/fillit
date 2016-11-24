/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:29:09 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/17 15:13:21 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_read(int argc, char *name, char *read_entry)
{
	int		fd;

	fd = 0;
	if (!read_entry)
		return (0);
	if (argc != 2)
		return (0);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	if (read(fd, read_entry, 4096) <= 0)
		return (0);
	return (1);
}
