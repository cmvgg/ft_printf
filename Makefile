# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 17:00:12 by cvarela-          #+#    #+#              #
#    Updated: 2024/11/22 21:44:23 by cvarela-         ###   ########.fr        #
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
	${RM} ${OBJS} $(TEST_OBJS) tests ft_printf_9 ft_printf_10 ft_printf_11 ft_printf_12

fclean: clean
	${RM} ${NAME} exits/*.txt  *.txt *.log test2

re: fclean all

TESTS = test_ft_printf.c test_integration.c test_stress.c print_test.c unity.c
TEST_OBJS = ${TESTS:.c=.o}

tests: all $(TEST_OBJS)
	$(CC) -o tests $(TEST_OBJS) $(OBJS) -L. -lftprintf
	$(CC) -o test2 main.c $(OBJS) -L. -lftprintf
	
run_tests: tests
	./tests
	chmod +x test_valgrind.sh
	./test_valgrind.sh >> exits/valgrind.txt
	chmod +x test_performance.sh
	./test_performance.sh >> exits/performance.txt
	chmod +x test_duration.sh
	./test_duration.sh >> exits/duration.txt
	chmod +x test_inyection.sh
	./test_inyection.sh >> exits/inyection.txt
	chmod +x test_overflow.sh
	./test_overflow.sh >> exits/overflow.txt
	chmod +x test_validation_input.sh
	./test_validation_input.sh >> exits/validation_input.txt
	chmod +x test_DoS.sh
	./test_DoS.sh >> exits/DoS.txt
	chmod +x test_logs.sh
	./test_logs.sh >> exits/logs.txt
	chmod +x test_compatibility_compilers.sh
	./test_compatibility_compilers.sh >> exits/compatibility_compilers.txt
	chmod +x test_time.sh
	./test_time.sh >> exits/time.txt
	chmod +x test_stress.sh
	./test_stress.sh >> exits/stress.txt
	chmod +x test_regresion.sh
	./test_regresion.sh >> exits/regresion.txt
	
.PHONY: clean fclean all re
