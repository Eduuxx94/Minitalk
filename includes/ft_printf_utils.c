/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:52:34 by ede-alme          #+#    #+#             */
/*   Updated: 2022/03/18 12:53:48 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_len(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

int	print_hexa(const char *format, unsigned int deci_num)
{
	unsigned int		temp;
	char				out[10];
	int					i;

	out[9] = 0;
	if (format[0] == 'X')
		out[9] = 32;
	i = 0;
	temp = deci_num;
	if (deci_num == 0)
		return (write(1, "0", 1));
	while (temp >= 16 && ++i)
		temp = temp / 16;
	out[i + 1] = '\0';
	while (deci_num > 0)
	{
		temp = deci_num % 16;
		if (temp < 10)
			out[i--] = temp + 48;
		else
			out[i--] = temp + 87 - out[9];
		deci_num = deci_num / 16;
	}
	return (write(1, out, string_len(out)));
}

int	print_unsigned(va_list *args)
{
	unsigned int	num;
	unsigned int	temp;
	char			out[15];
	int				i;

	num = va_arg(*args, unsigned int);
	temp = num;
	if (!num)
		return (write(1, "0", 1));
	i = 0;
	while (temp >= 10 && ++i)
		temp = temp / 10;
	out[i + 1] = '\0';
	while (num > 0)
	{
		out[i--] = num % 10 + 48;
		num = num / 10;
	}
	return (write(1, out, string_len(out)));
}

int	print_decimal(va_list *args)
{
	int		num;
	int		temp;
	char	out[15];
	int		i;

	num = va_arg(*args, int);
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num == 0)
		return (write(1, "0", 1));
	temp = num;
	i = 0;
	while ((temp >= 10 && ++i) || (temp <= -10 && ++i))
		temp = temp / 10;
	if (num < 0 && ++i)
		num = num * -1;
	out[i + 1] = '\0';
	out[0] = '-';
	while (num > 0)
	{
		out[i--] = num % 10 + 48;
		num = num / 10;
	}
	return (write(1, out, string_len(out)));
}

int	print_pointer(va_list *args)
{
	unsigned long int	deci_num;
	int					out;
	int					i;
	int					temp;
	char				hexi_num[17];

	i = 0;
	out = 0;
	out += write(1, "0x", 2);
	deci_num = va_arg(*args, unsigned long int);
	if (deci_num == 0)
		return (out += write(1, "0", 1));
	while (deci_num != 0)
	{
		temp = deci_num % 16;
		if (temp < 10)
			hexi_num[i++] = temp + 48;
		else
			hexi_num[i++] = temp + 87;
		deci_num = deci_num / 16;
	}
	hexi_num[i] = '\0';
	while (--i >= 0)
		out += write(1, &hexi_num[i], 1);
	return (out);
}
