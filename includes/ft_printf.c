/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:22:04 by ede-alme          #+#    #+#             */
/*   Updated: 2022/03/18 12:55:31 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list *args)
{
	char	*string;

	string = va_arg(*args, char *);
	if (!string)
		return (write(1, "(null)", 6));
	return (write(1, string, string_len(string)));
}

int	print_character(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	return (write(1, &c, 1));
}

int	print_flag(const char *format, va_list *args)
{
	if (*format == '%')
		return (write(1, "%%", 1));
	if (*format == 'c')
		return (print_character(args));
	if (*format == 's')
		return (print_string(args));
	if (*format == 'p')
		return (print_pointer(args));
	if (*format == 'd')
		return (print_decimal(args));
	if (*format == 'i')
		return (print_decimal(args));
	if (*format == 'u')
		return (print_unsigned(args));
	if (*format == 'x' || *format == 'X')
		return (print_hexa(format, va_arg(*args, unsigned int)));
	return (0);
}

int	print_text(const char *format, va_list *args)
{
	int	out;

	out = 0;
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			out += print_flag(format, args);
		}
		else
			out += write(1, format, 1);
		format++;
	}
	return (out);
}

int	ft_printf(const char *format, ...)
{
	int		out;
	va_list	args;

	out = 0;
	va_start(args, format);
	out = print_text(format, &args);
	va_end(args);
	return (out);
}
/*
int	main(void)
{
	int	read;

	read = ft_printf("minha: func: %i\n", -2147483649);
	printf("out: %i\n", read);
	read = printf("printf func: %i\n", -2147483649);
	printf("out: %i\n", read);
	//out = printf("minha func: %p \n", 0);
	//printf("out: %i\n", out);
}
*/