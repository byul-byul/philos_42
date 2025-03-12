# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 11:48:59 by bhajili           #+#    #+#              #
#    Updated: 2025/03/12 12:52:43 by bhajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   push_swap

D_HDR   =   ./
D_SRC   =   ./

CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror

SRCS    =   $(D_SRC)main.c \
			$(D_SRC)push_swap.c \
			$(D_SRC)initializator.c \
			$(D_SRC)validator.c \
			$(D_SRC)parser.c \
			$(D_SRC)cleaner.c \
			$(D_SRC)stack_operations_00.c \
			$(D_SRC)stack_operations_01.c \
			$(D_SRC)stack_operations_02.c \
			$(D_SRC)stack_operations_03.c \
			$(D_SRC)utils_00.c \
			$(D_SRC)utils_01.c \
			$(D_SRC)project_operations_00.c \
			$(D_SRC)project_operations_01.c \
			$(D_SRC)project_operations_02.c \
			$(D_SRC)operation_wrapper_00.c

OBJS    =   $(SRCS:.c=.o)

# Define the targets
all:	$(NAME)

# linking with dependencies on object files
$(NAME): $(OBJS) libft/libft.a
	$(CC) -o $@ $^ -Llibft -lft -o $(NAME)

# Library rule to build libft if needed
libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f libft/libft.a $(NAME)

re: fclean all

.PHONY: all libft clean fclean re bonus