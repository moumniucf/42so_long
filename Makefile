NAME = so_long
BNAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror 
MFLAG = -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c valid_map.c getnextline/get_next_line.c getnextline/get_next_line_utils.c move.c \
       press_key.c printf/ft_printf.c printf/ft_putchar.c printf/ft_puthex.c printf/ft_putnbr.c \
       printf/ft_putpoint.c printf/ft_putprc.c printf/ft_putstr.c printf/ft_putunsigned.c so_parsse.c \
       valid_path.c valid_char.c parsse_h2.c map_len.c error_han.c

HEADER = so_long.h
OBSRCS = $(SRCS:%.c=%.o)

BSRCS = bonus/so_long_bonus.c bonus/valid_map_bonus.c bonus/getnextline/get_next_line.c bonus/getnextline/get_next_line_utils.c bonus/move_bonus.c\
		bonus/press_key_bonus.c bonus/printf/ft_printf.c bonus/printf/ft_putchar.c bonus/printf/ft_puthex.c bonus/printf/ft_putnbr.c\
		bonus/printf/ft_putpoint.c bonus/printf/ft_putprc.c bonus/printf/ft_putstr.c bonus/printf/ft_putunsigned.c bonus/so_parsse_bonus.c\
		bonus/valid_chars2_bonus.c bonus/ft_itoa_bonus.c bonus/animation_bonus.c bonus/valid_path_bonus.c bonus/parsse2_bonus.c bonus/error_han_bonus.c\
		bonus/enemy_patrol_bonus.c

BHEADER = ./bonus/so_long_bonus.h
BOSRCS = $(BSRCS:%.c=%.o)

all: $(NAME)
bonus: $(BNAME)

$(NAME): $(OBSRCS)
	@$(CC) $(CFLAGS) $(MFLAG) $(OBSRCS) -o $(NAME)

$(BNAME): $(BOSRCS)  $(HEADER)
	@$(CC) $(CFLAGS) $(MFLAG) $(BOSRCS) -o $(BNAME)

%.o: %.c
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "Compiling" $< "to" $@

bonus/%.o: bonus/%.c $(BHEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "Compiling" $< "to" $@

clean:
	@rm -f $(OBSRCS) $(BOSRCS)

fclean: clean/
	@rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: clean