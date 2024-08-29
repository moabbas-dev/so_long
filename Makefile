NAME = so_long

FT_PRINTF = ft_printf

FT_PRINTF_LIB = ft_printf/libftprintf.a

MINI_LIB_DIR = minilibx

MINI_LIB = minilibx/libmlx.a

SRCS = srcs/so_long.c srcs/parse_map/parse_map.c srcs/parse_map/parsing_utils.c\
	   srcs/parse_map/utils.c srcs/parse_map/utils2.c\
	   srcs/game/game_utils.c srcs/game/events.c srcs/game/put_images.c\
	   srcs/game/events_utils.c

OBJCS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L./minilibx -lmlx -lX11 -lXext -lm

all: $(NAME) $(FT_PRINTF_LIB) $(MINI_LIB)

$(NAME): $(OBJCS)
	make -C $(FT_PRINTF)
	make -C $(MINI_LIB_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJCS) $(FT_PRINTF_LIB) $(MLX_FLAGS) $(MINI_LIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	make -C $(FT_PRINTF) clean
	make -C $(MINI_LIB_DIR) clean
	rm -f $(OBJCS)

fclean: clean
	make -C $(FT_PRINTF) fclean
	make -C $(MINI_LIB_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re