/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:59:30 by cvarela-          #+#    #+#             */
/*   Updated: 2024/11/22 13:29:07 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <time.h>
# include <string.h>
# include <fcntl.h>

int				ft_putchar(int c);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
int				ft_printf(const	char *str, ...);
int				ft_hexa_pointer(unsigned long hex);
int				ft_strlen(char *s);
int				ft_hexa(unsigned long n, int loworup);
int				ft_putnbru(unsigned int u);
int				ft_percent(char c, va_list list);

// TEST INTEGRACION //
void			setUp(void);
void			tearDown(void);
void			test_ft_printf_basic_formats(void);
void			test_ft_printf_with_null(void);
void			test_ft_printf_multiple_formats(void);
void			test_ft_printf_edge_cases(void);
void			test_large_string();
void			test_large_number();
void			test_multiple_calls();
void			test_large_hexadecimal();
void			test_empty_string();
void			test_performance();
void			log_result(const char *test_name, const char *result);
int				redirect_stdout_to_file(const char *filename);
void			restore_stdout(int saved_stdout);

#endif