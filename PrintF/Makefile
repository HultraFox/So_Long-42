# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 12:43:44 by fmontel           #+#    #+#              #
#    Updated: 2024/10/21 12:45:03 by fmontel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra -g
NAME= printf.a
SRC= ft_printf.c \
	ft_charchk.c \
	ft_putnbr.c \
	ft_puthex.c \
	ft_puthex_adrs.c \
	ft_putstr.c \
	ft_strlen.c \
	ft_u_putnbr.c

OBJ= $(SRC:.c=.o)

all : $(OBJ) $(NAME) 

$(NAME): $(OBJ)
			ar rc $(NAME) $(OBJ)
			
clean:
			rm -f $(OBJ)
fclean:
			rm -f $(NAME) $(OBJ)

re:			fclean all

.PHONY: all clean fclean re
