# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andi <andi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 13:17:35 by andi              #+#    #+#              #
#    Updated: 2023/11/13 20:35:17 by andi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c ft_printpointer_pf.c ft_putchard_pf.c ft_putlhex_pf.c ft_putnbr_pf.c \
		ft_putstr_pf.c ft_putstrrev_pf.c ft_putuhex_pf.c ft_putunsnbr_pf.c 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re