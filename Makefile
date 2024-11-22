# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 17:00:12 by cvarela-          #+#    #+#              #
#    Updated: 2024/11/22 13:30:55 by cvarela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc

RM = rm -f

RUN = ranlib

LIB = ar crs

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
		${LIB} ${NAME} ${OBJS}
		${RUN} ${NAME}

clean:
	${RM} ${OBJS} $(TEST_OBJS) tests 

fclean: clean
	${RM} ${NAME} *.txt

re: fclean all

TESTS = test_ft_printf.c test_integration.c test_stress.c print_test.c unity.c
TEST_OBJS = ${TESTS:.c=.o}

tests: all $(TEST_OBJS)
	$(CC) -o tests $(TEST_OBJS) $(OBJS) -L. -lftprintf
run_tests: tests
	./tests
	
.PHONY: clean fclean all re
