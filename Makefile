# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 12:18:32 by ablizniu          #+#    #+#              #
#    Updated: 2019/01/24 13:12:46 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRACTOL_NAME = Fract-ol

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3

# Libraries and Includes

FRACTOL_LIBRARIES = -lmlx -framework OpenGL -framework AppKit
FRACTOL_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)


# Headers

HEADERS_DIRECTORY = ./includes/

FRACTOL_HEADERS_LIST = \
	fractol.h \
	fractol_keys \
FRACTOL_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(FRACTOL_HEADERS_LIST))

# Sources

FRACTOL_SOURCES_DIRECTORY = ./src/
FRACTOL_SOURCES_LIST = \
	bonus_fractals.c \
	clean.c \
	colors.c \
	drawing.c \
	fractal.c \
	init.c \
	init_norme.c \
	key_events.c \
	key_utils.c \
	main.c \
	mandatory_fractals.c \
	mouse_events.c \
	print.c \
	utils.c
FRACTOL_SOURCES = $(addprefix $(FRACTOL_SOURCES_DIRECTORY), $(FRACTOL_SOURCES_LIST))

# Objects

OBJECTS_DIRECTORY = ./objects/


FRACTOL_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)fractol/
FRACTOL_OBJECTS_LIST = $(patsubst %.c, %.o, $(FRACTOL_SOURCES_LIST))
FRACTOL_OBJECTS	= $(addprefix $(FRACTOL_OBJECTS_DIRECTORY), $(FRACTOL_OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(FRACTOL_NAME)

$(FRACTOL_NAME): $(LIBFT) $(FRACTOL_OBJECTS_DIRECTORY) $(FRACTOL_OBJECTS)
	@$(CC) $(FLAGS) $(LIBFT) $(FRACTOL_LIBRARIES) $(FRACTOL_INCLUDES) $(FRACTOL_OBJECTS) -o $(FRACTOL_NAME)
	@echo "\n$(FRACTOL_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(FRACTOL_NAME): $(GREEN)$(FRACTOL_NAME) was created$(RESET)"

$(FRACTOL_OBJECTS_DIRECTORY):
	@mkdir -p $(FRACTOL_OBJECTS_DIRECTORY)
	@echo "$(FRACTOL_NAME): $(GREEN)$(FRACTOL_OBJECTS_DIRECTORY) was created$(RESET)"

$(FRACTOL_OBJECTS_DIRECTORY)%.o : $(FRACTOL_SOURCES_DIRECTORY)%.c $(FRACTOL_HEADERS)
	@$(CC) $(FLAGS) -c $(FRACTOL_INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(GREEN)$(LIBFT) was created$(RESET)"
	@$(MAKE) -C $(LIBFT_DIRECTORY)

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@echo "$(FRACTOL_NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(FRACTOL_NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(FRACTOL_NAME)
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	@echo "$(FRACTOL_NAME): $(RED)$(FRACTOL_NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all