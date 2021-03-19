NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c mini_libft.c input.c output_common.c output_char.c output_string.c output_hexadecimal.c output_pointer.c
OBJ = $(CFILES:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
bonus: $(OBJ)
	ar -rcs $(NAME) $(OBJ)
.PHONY: all clean fclean re bonus