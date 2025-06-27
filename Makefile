# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akok <akok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 15:54:33 by akok              #+#    #+#              #
#    Updated: 2025/06/27 17:03:33 by akok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

SRCS =	srcs/push_swap.c			\
		srcs/sorting/sort_mini.c	\
		srcs/sorting/turk.c			\
		srcs/parsing/parse_input.c	\
		srcs/do_op/do_op.c			\
		srcs/do_op/do_op_utils.c	\
		srcs/cost/cost.c			\
		srcs/cost/cost_utils.c		\
		srcs/cost/cost_utils2.c		\
		srcs/utils/utils.c			\
		srcs/ops/push.c				\
		srcs/ops/reverse_rotate.c	\
		srcs/ops/rotate.c			\
		srcs/ops/swap.c
		
OBJS = $(SRCS:%.c=%.o)

LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) is built."

$(LIBFT):
	@make --no-print-directory -C $(LIB_PATH) all
	@make --no-print-directory -C $(LIB_PATH) bonus

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	@rm -f $(OBJS)
	@make --no-print-directory -C $(LIB_PATH) clean
	@echo "$(NAME) object files removed."

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIB_PATH) fclean
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re bonus
