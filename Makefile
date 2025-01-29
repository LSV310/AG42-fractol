CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g3

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX			= mlx/libmlx.a

INCLUDES	= includes/
SRC_DIR		= srcs/
OBJ_DIR		= objs/

CFLAGS		+= -I$(INCLUDES)

CFLAGS		+= -D MAX_ITERATIONS=200
CFLAGS		+= -D ZOOM_FACTOR=1.08
CFLAGS		+= -D MOVE_FACTOR=0.1
CFLAGS		+= -D WIDTH=1920
CFLAGS		+= -D HEIGHT=1010

SRC			= main.c mlx.c hooks.c fract.c parsing.c events.c movements.c
OBJ			= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

NAME		= fractol

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLX) $(CFLAGS) -Lmlx -lmlx -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	make -sC $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -sC libft

re: fclean all

.PHONY: all bonus clean fclean re
