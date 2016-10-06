# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/10/06 16:59:57 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = npuzzle

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast -flto -march=native -g

INCLUDES_PATH = include/

SRCS_PATH = src/

SRCS_NAME = main.c \
			get_next_line.c \
			parse_file.c \
			valid_int.c \
			dump_state.c \
			state_list_push.c \
			state_list_remove.c \
			astar.c \
			state_new.c \
			build_end.c \
			state_new_size.c \
			state_equals.c \
			state_list_contains.c \
			state_list_free.c \
			state_free.c \
			state_expend.c \
			state_copy.c \
			manhattan.c \
			generate_random.c \
			is_solvable.c \
			epoch_millis.c \
			print_solution.c \
			state_list_size.c \
			misplaced.c \
			row_column.c \
			state_calc_score.c \
			state_cost.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make -C libft clean
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
