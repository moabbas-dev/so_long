NAME = libftprintf.a

LIBFT_LIB = libft/libft.a

LIBFT = libft

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_printf.c prints.c prints2.c utils.c

OBJCS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJCS)
	make -C $(LIBFT)
	cp $(LIBFT_LIB) $(NAME)
	ar -rcs $(NAME) $(OBJCS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus:
	ar -rcs $(NAME)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJCS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re