NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'
DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
WHITE='\033[1;37m'

NAME = cub3D

NAME_BONUS = cub3D_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRC_DIR = srcs

OBJ_DIR = objs

SRCS = 	$(SRC_DIR)/main.c \
					$(SRC_DIR)/data.c \
 					$(SRC_DIR)/errors.c \
 					$(SRC_DIR)/parser.c \
 					$(SRC_DIR)/free.c \
 					$(SRC_DIR)/map_analyze.c \
 					$(SRC_DIR)/getters.c \
 					$(SRC_DIR)/getters2.c \
 					$(SRC_DIR)/drawline.c \
 					$(SRC_DIR)/inputs.c \
 					$(SRC_DIR)/rotatemouse.c \
 					$(SRC_DIR)/movements.c \
 					$(SRC_DIR)/textures.c \
 					$(SRC_DIR)/minimap.c \
 					$(SRC_DIR)/door.c \

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@echo ${LIGHTBLUE}Libft compiling !${NOCOLOR}
	@make -C ./mlx
	@make -C ./Libft
	@echo ${LIGHTBLUE}$(NAME) compiling !${NOCOLOR}
	@$(CC) $(CFLAGS) -Imlx -framework OpenGL -framework AppKit $(OBJS) -o $@ ./Libft/libft.a mlx/libmlx.a
	@echo ${LIGHTGREEN}$(NAME) compiled !${NOCOLOR}

clean:
	@make clean -C ./Libft
	@echo ${LIGHTRED}Libft objects removed !${NOCOLOR}
	@rm -rf $(OBJ_DIR)
	@echo ${LIGHTRED}$(NAME) objects removed !${NOCOLOR}

fclean: clean
	@make fclean -C ./Libft
	@rm -f $(NAME)
	@echo ${LIGHTRED}$(NAME) removed !${NOCOLOR}

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
