/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:57:19 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/21 16:09:20 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	print_format(char specifier, va_list ap);
int	putchar(int c);
int	putstr(char *str);
int	print_digit(long n, int base);
int	print_digit_u(long n, int base);
int	print_digit_upperx(long n, int base);
int	print_pointer(unsigned long ptr);
int	print_digit_pointer(unsigned long n, unsigned long base);

#endif
