CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs

NAME = libftprintf.a

SRCS =  ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putnbr_u.c \
		ft_putnbr_hex.c \
		ft_putptr.c \

OBJS = $(SRCS:.c=.o)
INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re