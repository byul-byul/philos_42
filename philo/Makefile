# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 10:36:52 by bhajili           #+#    #+#              #
#    Updated: 2025/03/04 15:09:43 by bhajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   philo

D_HDR   =   ./
D_SRC   =   ./

CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror

SRCS    =   $(D_SRC)main.c \
			$(D_SRC)philo.c \
			$(D_SRC)validator.c \
			$(D_SRC)parser.c \
			$(D_SRC)initializator.c \
			$(D_SRC)simulator.c \
			$(D_SRC)utils_00.c \
			$(D_SRC)utils_01.c

OBJS    =   $(SRCS:.c=.o)

# Define the targets
all:    $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -o $(NAME)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus