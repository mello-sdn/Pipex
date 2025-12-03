NAME        = pipex
LIBFT       = ./libft/libft.a
INC         = include/
SRC_DIR     = srcs/
OBJ_DIR     = obj/
CC          = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INC)
RM          = rm -f

PIPEX_DIR = $(SRC_DIR)pipex.c \
            $(SRC_DIR)utils.c \
            $(SRC_DIR)handle_errors.c


SRCS        = $(PIPEX_DIR)
OBJS        = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))


start:
	@make all

$(LIBFT):
	@make -C ./libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: start all clean fclean re
