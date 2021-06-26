CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = sources/ft_printf.c

OBJS = ft_printf.o

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
