# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/13 21:32:12 by dsusheno          #+#    #+#              #
#    Updated: 2016/01/17 17:50:14 by dsusheno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = algo_final.c\
	  algo_param.c\
	  alloc_map.c\
	  comp_maps.c\
	  create_map_final.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_read.c\
	  ft_strlen.c\
	  verif_map.c\
	  verif_tetri.c\
	  stock_cord.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all :
	gcc -Werror -Wall -Wextra fillit.h -c $(SRC)
	gcc -Werror -Wall -Wextra main.c $(OBJ) -o fillit

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f fillit

re : fclean all
