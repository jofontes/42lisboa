/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:04:10 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/21 16:08:42 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = putchar(va_arg(ap, int));
	else if (specifier == 's')
		count = putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count = print_digit((long)va_arg(ap, int), 10);
	else if (specifier == 'p')
		count = print_pointer((unsigned long)va_arg(ap, void *));
	else if (specifier == 'u')
		count = print_digit_u(va_arg(ap, unsigned int), 10);
	else if (specifier == 'x')
		count = print_digit((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count = print_digit_upperx((long)va_arg(ap, unsigned int), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += print_format(format[++i], ap);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

// int main()
// {
//     int count;

//     count = ft_printf("%x\n", 123);
//     ft_printf("The chars written are %d\n\n", count);
// 	ft_printf("%p\n", "hello");
// 	printf("%p", "hello");
// }
