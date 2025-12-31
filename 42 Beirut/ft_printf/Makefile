NAME = libftprintf.a

INCLUDES = -I includes
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

SRCS = ft_printf_utils2.c \
       ft_printf_utils1.c \
       ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
