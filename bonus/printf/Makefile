# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 09:53:31 by youmoumn          #+#    #+#              #
#    Updated: 2025/03/24 11:29:25 by youmoumn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRC = ft_puthex_bonus.c ft_putchar_bonus.c ft_putnbr_bonus.c  ft_putstr_bonus.c ft_printf_bonus.c ft_putunsigned_bonus.c ft_putpoint_bonus.c ft_putprc_bonus.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "compiling" $< "to" $@

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean :
	@rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : clean fclean
