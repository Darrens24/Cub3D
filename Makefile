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

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRC_DIR = srcs

OBJ_DIR = objs

SRCS = 	$(SRC_DIR)/main.c 

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I ./headers -c $< -o $@

$(NAME): $(OBJS)
	@echo ${LIGHTBLUE}Libft compiling !${NOCOLOR}
	@make -C ./Libft
	@echo ${LIGHTBLUE}$(NAME) compiling !${NOCOLOR}
	@$(CC) $(CFLAGS) -I ./headers $(OBJS) -o $@ ./Libft/libft.a
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

.PHONY: all clean fclean re
