/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:24:23 by ede-alme          #+#    #+#             */
/*   Updated: 2022/03/18 12:41:47 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
//# include <stdio.h> //for test all fuctions

//This is the main functions
int	ft_printf(const char *format, ...);
int	print_text(const char *format, va_list *args);
int	print_flag(const char *format, va_list *args);
int	print_character(va_list *args);
int	print_string(va_list *args);

//This is the utils functions
int	print_pointer(va_list *args);
int	print_decimal(va_list *args);
int	print_unsigned(va_list *args);
int	print_hexa(const char *format, unsigned int deci_num);
int	string_len(const char *string);

#endif