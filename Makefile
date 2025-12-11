CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_printf.c \
		ft_putchar.c \
		ft_putnbr_base.c \
		ft_putptr.c \
		ft_putstr.c \
        ft_strlen.c \
		ft_print_formatted.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
