# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 10:36:52 by bhajili           #+#    #+#              #
#    Updated: 2025/04/09 13:36:57 by bhajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   philo_bonus

D_HDR   =   ./
D_SRC   =   ./

CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror
LDFLAGS =	-pthread

SRCS    =   $(D_SRC)main.c \
			$(D_SRC)philo_bonus.c \
			$(D_SRC)validator.c \
			$(D_SRC)parser.c \
			$(D_SRC)initializator.c \
			$(D_SRC)simulator_00.c \
			$(D_SRC)simulator_01.c \
			$(D_SRC)simulator_02.c \
			$(D_SRC)cleaner.c \
			$(D_SRC)utils_00.c \
			$(D_SRC)utils_01.c \
			$(D_SRC)utils_02.c \
			$(D_SRC)utils_03.c

OBJS    =   $(SRCS:.c=.o)

# Define the targets
all:    $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) -o $(NAME)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re