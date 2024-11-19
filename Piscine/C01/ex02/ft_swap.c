/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:11:34 by josaraiv          #+#    #+#             */
/*   Updated: 2024/09/28 17:38:57 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*
int main()
{
	int a;
	int b;
	
	a=1;
	b=2;
	printf ("a= %d\n", a);
	printf ("b= %d\n", b);
	ft_swap(&a, &b);
	printf ("a= %d\n", a);
	printf ("b= %d\n", b);
}
*/