/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:04:10 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/22 11:58:45 by josaraiv         ###   ########.fr       */
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

/*
int main()
{
    int count;
	printf("test with text only\n");
	count = printf("hello world\n");
	printf("The chars written are %d\n", count);
    count = ft_printf("hello world\n");
	ft_printf("The chars written are %d\n\n", count);
	
	printf("test with %%\n");
	count = printf("hello world %%\n");
	printf("The chars written are %d\n", count);
    count = ft_printf("hello world %%\n");
	ft_printf("The chars written are %d\n\n", count);

	printf("test c\n");
	count = printf("%c\n", 'a');
	printf("The chars written are %d\n", count);
    count = ft_printf("%c\n", 'a');
	ft_printf("The chars written are %d\n\n", count);

	printf("test s\n");
	count = printf("%s\n", "hello world");
	printf("The chars written are %d\n", count);
    count = ft_printf("%s\n", "hello world");
	ft_printf("The chars written are %d\n\n", count);

	printf("test p\n");
	count = printf("%p\n", "hello world");
	printf("The chars written are %d\n", count);
    count = ft_printf("%p\n", "hello world");
	ft_printf("The chars written are %d\n\n", count);

	printf("test p\n");
	count = printf("%p\n",NULL);
	printf("The chars written are %d\n", count);
    count = ft_printf("%p\n",NULL);
	ft_printf("The chars written are %d\n\n", count);

	printf("test d\n");
	count = printf("%d\n",123);
	printf("The chars written are %d\n", count);
    count = ft_printf("%d\n",123);
	ft_printf("The chars written are %d\n\n", count);

	printf("test d\n");
	count = printf("%d\n", -123);
	printf("The chars written are %d\n", count);
    count = ft_printf("%d\n", -123);
	ft_printf("The chars written are %d\n\n", count);
	
	printf("test i\n");
	count = printf("%i\n",123);
	printf("The chars written are %d\n", count);
    count = ft_printf("%i\n",123);
	ft_printf("The chars written are %d\n\n", count);

	printf("test i\n");
	count = printf("%i\n", -123);
	printf("The chars written are %d\n", count);
    count = ft_printf("%i\n", -123);
	ft_printf("The chars written are %d\n\n", count);

	printf("test u\n");
	count = printf("%u\n", 123);
	printf("The chars written are %d\n", count);
    count = ft_printf("%u\n", 123);
	ft_printf("The chars written are %d\n\n", count);

	printf("test x\n");
	count = printf("%x\n", 123);
	printf("The chars written are %d\n", count);
    count = ft_printf("%x\n", 123);
	ft_printf("The chars written are %d\n\n", count);
	
	printf("test X\n");
	count = printf("%X\n", 123);
	printf("The chars written are %d\n", count);
    count = ft_printf("%X\n", 123);
	ft_printf("The chars written are %d\n\n", count);
	
}
*/

/*
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

#define FAIL "***************** TEST FAILED **********************\n\n"

int	main(void)
{
	int a;
	int b;

	// x tests
	printf("x tests\n");
	printf(" printf out\n%d printf length\n", a = printf("%x", 0));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 0));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", -1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", -1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", 1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", 10));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 10));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", 99));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 99));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", -101));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", -101));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x",
			INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", INT_MIN));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x",
			INT_MIN));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", UINT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x",
			UINT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x %x %x %x", INT_MAX,
			INT_MIN, 0, -42));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x %x %x %x",
			INT_MAX, INT_MIN, 0, -42));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// X tests
	printf("X tests\n");
	printf(" printf out\n%d printf length\n", a = printf("%X", 0));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 0));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", -1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", -1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", 1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", 10));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 10));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", 99));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 99));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", -101));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", -101));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X",
			INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", INT_MIN));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X",
			INT_MIN));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", UINT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X",
			UINT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X %X %X %X", INT_MAX,
			INT_MIN, 0, -42));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X %X %X %X",
			INT_MAX, INT_MIN, 0, -42));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// c tests
	printf("c tests\n");
	printf(" printf out\n%d printf length\n", a = printf("%c", '0'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c", '0'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c", '0'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c", '0'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%c ", '0'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c ", '0'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c ", '0'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c ", '0'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c", '0' - 256));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c", '0'
			- 256));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%c ", '0' + 256));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c ", '0'
			+ 256));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c %c %c ", '1', '2',
			'3'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c %c %c ",
			'1', '2', '3'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%c ", '0' + 256));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c ", '0'
			+ 256));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c %c %c ", '1', '2',
			'3'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c %c %c ",
			'1', '2', '3'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// d & i tests
	printf("d & i tests\n");
	printf(" printf out\n%d printf length\n", a = printf(" %d ", -99));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ", -99));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %d ", 100));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ", 100));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %d ", INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ",
			INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %d ", INT_MIN));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ",
			INT_MIN));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %d ", UINT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ",
			UINT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// p tests
	printf("p tests\n");
	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)-1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			(void *)-1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			(void *)1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)15));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			(void *)15));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)0));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			(void *)0));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf("p tests\n");
	printf(" printf out\n%d printf length\n", a = printf(" %p ", NULL));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			NULL));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p %p ",
			(void *)LONG_MIN, (void *)LONG_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p %p ",
			(void *)LONG_MIN, (void *)LONG_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p %p ",
			(void *)INT_MIN, (void *)INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p %p ",
			(void *)INT_MIN, (void *)INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p %p ",
			(void *)ULONG_MAX, (void *)-ULONG_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p %p ",
			(void *)ULONG_MAX, (void *)-ULONG_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// s tests

	char *s = "this is a longer test string to test printf";

	printf("s tests\n");
	printf(" printf out\n%d printf length\n", a = printf("%s", ""));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%s", ""));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %s %s ", "", "-"));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %s %s ", "",
			"-"));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// u tests
	printf("u tests\n");
	printf(" printf out\n%d printf length\n", a = printf(" %u ", -100));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
			-100));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %u ", INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
			INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %u ", INT_MIN));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
			INT_MIN));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %u ", UINT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
			UINT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

}
*/
