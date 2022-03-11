/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:18:04 by fmalizia          #+#    #+#             */
/*   Updated: 2022/03/11 10:46:25 by fmalizia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putint(int n);
int	ft_putnbr(unsigned int n, int base);
int	ft_putchar(char c);
int	ft_printf(char *format, ...);

int	ft_putstr(char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		i += ft_putchar(str[i]);
	return(i);	
}

int	ft_putint(int n)
{
	int	count = 0;

	if ( n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	count += ft_putnbr(n, 10);
	return (count);
}

int	ft_putnbr(unsigned int n, int base)
{
	char	base_set[] = "0123456789abcdef";
	int		count = 0;
	int		i = 0;
	
	if (n / base > 0)
		count += ft_putnbr(n / base, base);
	i = n % base;
	count += ft_putchar(base_set[i]);
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(char *format, ...)
{
	int	count = 0;
	va_list		args;
	int	i = 0;

	va_start(args, format);
	while(format[i])
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] == 'd')
				count += ft_putint(va_arg(args, int));
			if (format[i] == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
			if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
		}
		else
			count += ft_putchar(format[i]);
		++i;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	char	*str = "This is a string";
	char	*empty = NULL;
	int		integer = -6325;
	int		hexadecimal = 32;
	printf(" : (%d) bytes printed\n", ft_printf("(%s)", str));
	printf(" : (%d) bytes printed\n", ft_printf("(%s)", empty));
	printf(" : (%d) bytes printed\n", ft_printf("(%d)", integer));
	printf(" : (%d) bytes printed\n", ft_printf("(%x)", hexadecimal));
	return (0);
}
*/
