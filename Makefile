NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MFLAG = -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c valid_map.c getnextline/get_next_line.c getnextline/get_next_line_utils.c move.c\
press_key.c

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