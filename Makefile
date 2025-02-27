NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address 

MFLAG = -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c valid_map.c getnextline/get_next_line.c getnextline/get_next_line_utils.c move.c\
press_key.c printf/ft_printf.c printf/ft_putchar.c printf/ft_puthex.c printf/ft_putnbr.c\
printf/ft_putpoint.c printf/ft_putprc.c printf/ft_putstr.c printf/ft_putunsigned.c so_parsse.c\
valid_path.c

HEADER = so_long.h

OBSRSC = $(SRCS:%.c=%.o)

all : $(NAME)

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "compiling" $< "to" $@

$(NAME) : $(OBSRSC)
	@$(CC) $(CFLAGS) $(MFLAG) $(OBSRSC) -o $(NAME)

clean : 
	@rm -f $(OBSRSC)

fclean : clean
	@rm -f $(NAME)

re : fclean all