NAME = libftprintf.a
SRC = ft_ptr.c \
	ft_putchar.c \
	ft_puthex.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putuphex.c \
	ft_u_putnbr.c \
	ft_printf.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -rc $(NAME) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re