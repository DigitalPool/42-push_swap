# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 18:34:58 by ashobajo          #+#    #+#              #
#    Updated: 2024/08/29 19:30:39 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -fPIC

SRCS =	sources/ft_add_args_to_stack.c \
			sources/ft_check_args.c \
			sources/ft_check_duplicate.c \
			sources/ft_check_if_sorted.c \
			sources/ft_create_new_node.c \
			sources/ft_find_means.c \
			sources/ft_free_stack.c \
			sources/ft_get_lst_size.c \
			sources/ft_get_stack.c \
			sources/ft_move_counts.c \
			sources/ft_print_error.c \
			sources/ft_sort_stack.c \
			sources/ft_sort.c \
			sources/ft_stack_means.c \
			sources/ft_stack_utils.c \
			sources/ft_parse_args_quoted.c \
			sources/push_operations.c \
			sources/ft_split_string.c \
			sources/push_swap.c \
			sources/rev_rotate_operations.c \
			sources/rotate_operations.c \
			sources/sorting_utils_ab.c \
			sources/sorting_utils_ba.c \
			sources/swap_operations.c\
			sources/ft_sort_100.c\
			sources/ft_push_tob_on.c\
			sources/pushes_tmp.c\

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJS): | $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean :
	$(RM) $(OBJS)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

.PHONY: all clean fclean re
