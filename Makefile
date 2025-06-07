# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akok <akok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 15:54:33 by akok              #+#    #+#              #
#    Updated: 2025/06/07 13:24:44 by akok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = swap.c push.c rotate.c reverse_rotate.c parse_input.c free_utils.c main.c

OBJS = $(SRCS:%.c=%.o)

LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a

NAME = push_swap

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIB_PATH) all
	make -C $(LIB_PATH) bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJS)
	make -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus
