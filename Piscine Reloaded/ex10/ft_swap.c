/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:10:56 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/24 11:17:49 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
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
