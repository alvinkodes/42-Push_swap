# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akok <akok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 15:54:33 by akok              #+#    #+#              #
#    Updated: 2025/06/30 10:21:38 by akok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

COMMON_SRCS = 	srcs/sorting/sort_mini.c	\
				srcs/sorting/turk.c			\
				srcs/parsing/parse_input.c	\
				srcs/parsing/parse_utils.c	\
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
				
SRCS =	srcs/push_swap.c	\
		$(COMMON_SRCS)
		

BONUS =	bonus/checker.c			\
		bonus/checker_utils.c	\
		$(COMMON_SRCS)
	
OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS:%.c=%.o)

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

bonus: $(CHECKER) $(LIBFT)

$(CHECKER): $(BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(CHECKER)
	@echo "$(CHECKER) is built."
	
clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make --no-print-directory -C $(LIB_PATH) clean
	@echo "$(NAME) and $(CHECKER) object files removed."

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@make --no-print-directory -C $(LIB_PATH) fclean
	@echo "$(NAME) and $(CHECKER) removed."

re: fclean all

.PHONY: all clean fclean re bonus
