CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = sources/ft_printf.c sources/flag_parsing.c sources/dec_int_handler.c \
		sources/char_handler.c sources/width_handler.c sources/str_handler.c \
		sources/mod_putstr.c sources/ptr_handler.c sources/atoi_base.c \
		sources/dec_int_handler.c sources/uint_handler.c sources/u_itoa.c \
		sources/hex_handler.c

OBJS = ft_printf.o flag_parsing.o dec_int_handler.o char_handler.o \
		width_handler.o str_handler.o mod_putstr.o ptr_handler.o atoi_base.o \
		dec_int_handler.o uint_handler.o u_itoa.o hex_handler.o

INCLUDES = -I./includes

all: $(NAME)

$(NAME):
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all
