# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 11:29:15 by tkubanyc          #+#    #+#              #
#    Updated: 2024/05/13 12:16:55 by tkubanyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	= push_swap.c \
			exit_handler.c \
			input_handler.c \
			input_handler_utils.c \
			operations_push.c \
			operations_swap.c \
			operations_rotate.c \
			operations_rev_rotate.c \
			sorting.c \
			sorting_utils.c \

HEADER	= push_swap.h

LIBFT_SRC	= libft_own/libft.a
PRINTF_SRC	= libft_own/ft_printf/libftprintf.a
GNL_SRC		= libft_own/ft_get_next_line/get_next_line.c \
				libft_own/ft_get_next_line/get_next_line_utils.c \

OBJDIR	= obj
OBJS 	= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
GNL_OBJ = $(patsubst libft_own/%.c, $(OBJDIR)/%, $(GNL_SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJ)
	$(MAKE) -C libft_own/ft_printf
	$(MAKE) -C libft_own
	$(CC) $(CFLAGS) $(GNL_OBJ) $(LIBFT_SRC) $(PRINTF_SRC) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.c $(HEADER) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(MAKE) -C libft_own/ft_printf clean
	$(MAKE) -C libft_own clean
	$(RM) -r $(OBJDIR)
	$(RM) $(addprefix libft_own/ft_get_next_line/, $(notdir $(GNL_SRC:.c=.o)))
	$(RM) $(LIBFT_SRC)
	$(RM) $(PRINTF_SRC)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
