/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:03:22 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/22 12:04:05 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar(int c)
{
	return (write(1, &c, 1));
}

int	putstr(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		putchar((int)str[i]);
		count++;
		i++;
	}
	return (count);
}

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
	{
		return (putchar(symbols[n]));
	}
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

int	print_digit_u(long n, int base)
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
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

int	print_digit_upperx(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit_upperx(-n, base) + 1);
	}
	else if (n < base)
	{
		return (putchar(symbols[n]));
	}
	else
	{
		count = print_digit_upperx(n / base, base);
		return (count + print_digit_upperx(n % base, base));
	}
}
