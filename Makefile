NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -c -g

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
