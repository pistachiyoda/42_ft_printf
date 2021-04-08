NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c mini_libft_1.c mini_libft_2.c input.c output_common.c output_integer.c output_char.c output_string.c output_hexadecimal.c output_pointer.c output_percent.c output_u_integer.c output_hexa_common.c proc_digit.c
OBJ = $(CFILES:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re