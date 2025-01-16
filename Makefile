CC			= cc
CFLAGS		= -g3 # -Wall -Werror -Wextra

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX			= mlx/libmlx.a

INCLUDES	= includes/
SRC_DIR		= srcs/
OBJ_DIR		= objs/

CFLAGS		+= -I$(INCLUDES)

SRC			= main.c mlx.c fract.c
OBJ			= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

NAME		= fractol

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -Lmlx -lmlx -lXext -lX11 -lm $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

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
