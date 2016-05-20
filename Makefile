# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/05/20 09:06:44 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = npuzzle

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.c \
			get_next_line.c \
			parse_file.c \
			valid_int.c \
			dump_puzzle.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make -C libft/ clean
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
