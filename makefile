# Assignations
NAME = so_long

SRCS = check_map.c so_long.c utils.c utils_game.c read_map.c load_images.c key_control.c coin_exit_accesibility.c
GNL_DIR = get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

OBJ_DIR = objSo_long
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
GNL_OBJS = $(GNL_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iminilibx -I$(GNL_DIR) -Ift_printf

RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MINILIBX_DIR = ./minilibx
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a 


all: $(LIBFT) $(PRINTF) $(MINILIBX_LIB) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(MINILIBX_LIB):
	@make -C $(MINILIBX_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@	

$(GNL_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF) $(MINILIBX_FLAGS)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(GNL_OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(MINILIBX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
