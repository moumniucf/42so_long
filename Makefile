# NAME = so_long
# BNAME = so_long_bonus

# CC = cc
# CFLAGS = -Wall -Wextra -Werror 
# MFLAG = -lmlx -framework OpenGL -framework AppKit

# SRCS = so_long.c valid_map.c getnextline/get_next_line.c getnextline/get_next_line_utils.c move.c \
#        press_key.c printf/ft_printf.c printf/ft_putchar.c printf/ft_puthex.c printf/ft_putnbr.c \
#        printf/ft_putpoint.c printf/ft_putprc.c printf/ft_putstr.c printf/ft_putunsigned.c so_parsse.c \
#        valid_path.c valid_char.c parsse_h2.c map_len.c error_han.c

# BSRCS = bonus/so_long_bonus.c bonus/valid_map_bonus.c bonus/getnextline/get_next_line.c bonus/getnextline/get_next_line_utils.c bonus/move_bonus.c\
# bonus/press_key_bonus.c bonus/printf/ft_printf.c bonus/printf/ft_putchar.c bonus/printf/ft_puthex.c bonus/printf/ft_putnbr.c\
# bonus/printf/ft_putpoint.c bonus/printf/ft_putprc.c bonus/printf/ft_putstr.c bonus/printf/ft_putunsigned.c bonus/so_parsse_bonus.c\
# bonus/valid_chars2_bonus.c bonus/ft_itoa_bonus.c bonus/animation_bonus.c bonus/valid_path_bonus.c bonus/parsse2_bonus.c bonus/error_han_bonus.c\
# bonus/enemy_patrol_bonus.c
# HEADER = so_long.h
# BHEADER = bonus/so_long_bonus.h

# OBSRCS = $(SRCS:%.c=%.o)
# BOSRCS = $(BSRCS:%.c=%.o)

# all: $(NAME)
# bonus: $(BNAME)

# $(NAME): $(OBSRCS) $(HEADER)
# 	@$(CC) $(CFLAGS) $(MFLAG) $(OBSRCS) -o $(NAME)

# $(BNAME): $(BOSRCS) $(BHEADER)
# 	@$(CC) $(CFLAGS) $(MFLAG) $(BOSRCS) -o $(BNAME)

# %.o: %.c $(HEADER)
# 	@$(CC) -c $< $(CFLAGS) -o $@
# 	@echo "Compiling" $< "to" $@

# clean:
# 	@rm -f $(OBSRCS) $(BOSRCS)

# fclean: clean
# 	@rm -f $(NAME) $(BNAME)

# re: fclean all

# .PHONY: clean
NAME = so_long
NAME_BON = so_long_Bonus

SRC = so_long.c valid_map.c getnextline/get_next_line.c getnextline/get_next_line_utils.c move.c \
       press_key.c printf/ft_printf.c printf/ft_putchar.c printf/ft_puthex.c printf/ft_putnbr.c \
       printf/ft_putpoint.c printf/ft_putprc.c printf/ft_putstr.c printf/ft_putunsigned.c so_parsse.c \
       valid_path.c valid_char.c parsse_h2.c map_len.c error_han.c
OBJC = $(SRC:.c=.o)

SRC_BON =  bonus/so_long_bonus.c bonus/valid_map_bonus.c bonus/getnextline/get_next_line.c bonus/getnextline/get_next_line_utils.c bonus/move_bonus.c\
bonus/press_key_bonus.c bonus/printf/ft_printf.c bonus/printf/ft_putchar.c bonus/printf/ft_puthex.c bonus/printf/ft_putnbr.c\
bonus/printf/ft_putpoint.c bonus/printf/ft_putprc.c bonus/printf/ft_putstr.c bonus/printf/ft_putunsigned.c bonus/so_parsse_bonus.c\
bonus/valid_chars2_bonus.c bonus/ft_itoa_bonus.c bonus/animation_bonus.c bonus/valid_path_bonus.c bonus/parsse2_bonus.c bonus/error_han_bonus.c\
bonus/enemy_patrol_bonus.c

OBJC_BON = $(SRC_BON:.c=.o)

INC = -I ./mandatory -I ./minilibx
INC_BON = -I ./Bonus -I ./minilibx
MLX_DIR = ./minilibx
CFLAGS = -Wall -Wextra -Werror 
CC = cc

MLX_FLAGS = -L ./minilibx -lmlx -lXext -lX11


all: $(MLX_LIB) ${NAME}

Bonus: $(MLX_LIB) $(NAME_BON)

${NAME} : ${OBJC}
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJC)  $(MLX_FLAGS) -o $(NAME)

${NAME_BON} : ${OBJC_BON}
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS)  $(OBJC_BON)  $(MLX_FLAGS) -o $(NAME_BON)

%.o: %.c ./mandatory/so_long.h
	$(CC)  $(CFLAGS) $(INC) -c $<  -o $@

Bonus/%.o: Bonus/%.c ./Bonus/so_long_bonus.h
	$(CC)  $(CFLAGS) $(INC_BON) -c $<  -o $@



clean:
	rm -rf  $(OBJC) $(OBJC_BON)
	make -C $(MLX_DIR) clean

fclean: clean 
	rm -rf $(NAME) $(NAME_BON)
	make -C $(MLX_DIR) fclean

re :  fclean all 