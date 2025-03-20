# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 12:50:03 by inowak--          #+#    #+#              #
#    Updated: 2025/03/20 02:02:08 by inowak--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################
#        Color         #
########################

RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
CYAN   = \033[1;36m
PURPLE = \033[1;35m
SPRUCE_GREEN = \033[38;2;0;102;51m
KING_BLUE = \033[38;2;65;105;225m
RESET  = \033[0m

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = cub3d

SRC = src/main.c\
		src/parsing/parsing.c\
		src/parsing/create_map.c\
		src/parsing/identifier.c\
		src/parsing/flood_fill.c\
		GNL/get_next_line.c\
		GNL/get_next_line_utils.c\

OBJ_DIR = .objects
INCLUDE_DIR = includes
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_DIR = libft
OBJ_LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJ_LIBFT):
	@cd $(LIBFT_DIR) && make bonus >> /dev/null

$(NAME): $(OBJ) $(OBJ_LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_LIBFT) -L$(LIBFT_DIR) -I$(LIBFT_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(INCLUDE_DIR) -O0 -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_LIBFT)
	@cd $(LIBFT_DIR) && make clean > /dev/null
	@printf "$(GREEN)clean$(RESET)\n"
fclean: clean
	@printf "$(RED)fclean$(RESET)\n"
	@rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re