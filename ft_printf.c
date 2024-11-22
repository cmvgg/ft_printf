/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:59:57 by cvarela-          #+#    #+#             */
/*   Updated: 2024/11/22 11:02:22 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'p')
		return (ft_hexa_pointer(va_arg(list, unsigned long)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(list, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (c == 'u')
		return (ft_putnbru(va_arg(list, unsigned int)));
	else if (c == 'x')
		return (ft_hexa(va_arg(list, unsigned int), 1));
	else if (c == 'X')
		return (ft_hexa(va_arg(list, unsigned int), 2));
	else
		return (ft_putchar('%'));
}

int	ft_hexa(unsigned long n, int loworup)
{
	char	c;
	int		count;
	char	*str;

	count = 0;
	if (loworup == 1)
	str = "0123456789abcdef";
	else
	str = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_hexa(n / 16, loworup);
	c = str[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_hexa_pointer(unsigned long hex)
{
	int		re_hex;

	re_hex = 2;
	if (write (1, "0x", 2) == -1)
		return (-1);
	re_hex += ft_hexa(hex, 1);
	return (re_hex);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		e;
	int		c;

	i = 0;
	c = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			e = ft_percent (format [i + 1], list);
			i += 2;
		}
		else
			e = ft_putchar(format[i++]);
		if (e == -1)
			return (-1);
		c += e;
	}
	return (c);
}

/*int main()
{
	ft_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
}*/