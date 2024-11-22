/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:09:03 by cvarela-          #+#    #+#             */
/*   Updated: 2023/11/11 16:48:06 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbr(int n)
{
	int		ret;
	char	c;

	ret = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ret += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ret += ft_putnbr(n / 10);
	c = n % 10 + '0';
	ret += ft_putchar(c);
	return (ret);
}

int	ft_putnbru(unsigned int u)
{
	int		ret;
	char	c;

	ret = 0;
	if (u > 9)
		ret += ft_putnbr(u / 10);
	c = u % 10 + '0';
	ret += ft_putchar(c);
	return (ret);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (*s)
	{
		ft_putchar(*s++);
		i ++;
	}
	return (i);
}

int	ft_putchar(int c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}
