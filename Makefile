# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 17:12:19 by sgalasso          #+#    #+#              #
#    Updated: 2018/10/17 13:28:54 by sgalasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC =	main.c \
		srcs/ft_is_room.c \
		srcs/ft_is_tunnel.c \
		srcs/ft_tab_add.c \
		srcs/ft_stock_next_in.c \
		srcs/ft_stock_next_out.c \
		srcs/ft_stock_room.c \
		srcs/ft_stock_next_rooms.c \
		srcs/ft_parse_input.c \
		srcs/ft_init_power.c \
		srcs/ft_handle_ants.c \
		srcs/ft_free_all.c \
		srcs/ft_stradd.c \
		srcs/ft_isnumber.c \
		srcs/ft_parse_room.c \

OBJ = $(SRC:.c=.o)

INCLUDES = includes

all: lib $(NAME)

$(NAME): $(OBJ) libft/libft.a libft/$(INCLUDES)/libft.h
	gcc -Wall -Wextra -Werror -o $(NAME) libft/libft.a $(OBJ) -I $(INCLUDES) -I ./libft/$(INCLUDES)

lib:
	make -C libft/

%.o: %.c $(INCLUDES)/lem_in.h libft/$(INCLUDES)/libft.h
	gcc -Wall -Wextra -Werror -o $@ -c $< -I $(INCLUDES) -I ./libft/$(INCLUDES)

clean:
	rm -f $(OBJ) && make -C libft/ clean

fclean: clean
	rm -f $(NAME) && make -C libft/ fclean

re: fclean all
