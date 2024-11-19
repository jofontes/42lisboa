/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:43:13 by josaraiv          #+#    #+#             */
/*   Updated: 2024/09/28 17:44:58 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
/*
int main ()
{
	int a;
	int b;
	a = 10;
	b = 2;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	ft_ultimate_div_mod(&a, &b);
	printf("Div (a) = %d\n", a);
	printf("Resto (b) = %d\n", b);
	
}
*/