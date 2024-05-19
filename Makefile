# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 11:29:15 by tkubanyc          #+#    #+#              #
#    Updated: 2024/05/19 13:25:11 by tkubanyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CHECKER	= checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC_DIR   = src
BONUS_DIR = $(SRC_DIR)/bonus
EXIT_HANDLER_DIR  = $(SRC_DIR)/exit_handler
INPUT_HANDLER_DIR = $(SRC_DIR)/input_handler
OPERATIONS_DIR	= $(SRC_DIR)/operations
SORTING_DIR = $(SRC_DIR)/sorting
INCLUDE_DIR = include

OBJDIR = obj
BONUS_OBJDIR = $(OBJDIR)/bonus
EXIT_HANDLER_OBJDIR  = $(OBJDIR)/exit_handler
INPUT_HANDLER_OBJDIR = $(OBJDIR)/input_handler
OPERATIONS_OBJDIR = $(OBJDIR)/operations
SORTING_OBJDIR = $(OBJDIR)/sorting

SRCS = $(SRC_DIR)/push_swap.c \
		$(EXIT_HANDLER_DIR)/exit_handler.c \
		$(INPUT_HANDLER_DIR)/input_handler.c \
		$(INPUT_HANDLER_DIR)/input_handler_utils.c \
		$(INPUT_HANDLER_DIR)/update_stack_values.c \
		$(OPERATIONS_DIR)/operations_push.c \
		$(OPERATIONS_DIR)/operations_swap.c \
		$(OPERATIONS_DIR)/operations_rotate.c \
		$(OPERATIONS_DIR)/operations_rev_rotate.c \
		$(SORTING_DIR)/sorting.c \
		$(SORTING_DIR)/sorting_utils.c \
		$(SORTING_DIR)/sort_3_elements.c \
		$(SORTING_DIR)/sort_small_stack.c \
		$(SORTING_DIR)/sort_big_stack.c

CHECKER_SRC = $(BONUS_DIR)/checker_bonus.c \
				$(BONUS_DIR)/operations_push_bonus.c \
				$(BONUS_DIR)/operations_swap_bonus.c \
				$(BONUS_DIR)/operations_rotate_bonus.c \
				$(BONUS_DIR)/operations_rev_rotate_bonus.c \
				$(EXIT_HANDLER_DIR)/exit_handler.c \
				$(INPUT_HANDLER_DIR)/input_handler.c \
				$(INPUT_HANDLER_DIR)/input_handler_utils.c \
				$(INPUT_HANDLER_DIR)/update_stack_values.c \
				$(OPERATIONS_DIR)/operations_push.c \
				$(OPERATIONS_DIR)/operations_swap.c \
				$(OPERATIONS_DIR)/operations_rotate.c \
				$(OPERATIONS_DIR)/operations_rev_rotate.c \
				$(SORTING_DIR)/sorting.c \
				$(SORTING_DIR)/sorting_utils.c \
				$(SORTING_DIR)/sort_3_elements.c \
				$(SORTING_DIR)/sort_small_stack.c \
				$(SORTING_DIR)/sort_big_stack.c

HEADER = $(INCLUDE_DIR)/push_swap.h
HEADER_BONUS = $(INCLUDE_DIR)/push_swap_bonus.h

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF_DIR	= $(LIBFT_DIR)/ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a
GNL_SRCS	= $(LIBFT_DIR)/ft_get_next_line/get_next_line.c \
			$(LIBFT_DIR)/ft_get_next_line/get_next_line_utils.c
GNL_OBJS	= $(patsubst $(LIBFT_DIR)/ft_get_next_line/%.c, $(OBJDIR)/ft_get_next_line/%.o, $(GNL_SRCS))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
CHECKER_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJDIR)/%.o, $(CHECKER_SRC))

DIRS = $(OBJDIR) $(BONUS_OBJDIR) $(EXIT_HANDLER_OBJDIR) $(INPUT_HANDLER_OBJDIR) $(OPERATIONS_OBJDIR) $(SORTING_OBJDIR) $(OBJDIR)/ft_get_next_line

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL_OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF)

bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJS) $(LIBFT) $(PRINTF) $(GNL_OBJS)
	$(CC) $(CFLAGS) -o $@ $(CHECKER_OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF)

$(OBJDIR)/%.o: $(SRC_DIR)/%.c $(HEADER) $(HEADER_BONUS) | $(DIRS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJDIR)/ft_get_next_line/%.o: $(LIBFT_DIR)/ft_get_next_line/%.c | $(OBJDIR)/ft_get_next_line
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(DIRS):
	mkdir -p $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
