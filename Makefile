# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 17:00:12 by cvarela-          #+#    #+#              #
#    Updated: 2023/11/11 17:00:16 by cvarela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc

RM = rm -f

RUN = ranlib

LIB = ar crs

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
		ft_printf_utils.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
		${LIB} ${NAME} ${OBJS}
		${RUN} ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re
