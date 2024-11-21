/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:08:15 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/21 16:20:54 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (count += putstr("(nil)"));
	count += putstr("0x");
	count += print_digit_pointer(ptr, 16);
	return (count);
}

int	print_digit_pointer(unsigned long n, unsigned long base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < base)
	{
		return (putchar(symbols[n]));
	}
	else
	{
		count = print_digit_pointer(n / base, base);
		return (count + print_digit_pointer(n % base, base));
	}
}
