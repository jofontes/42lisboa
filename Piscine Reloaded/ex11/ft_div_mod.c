/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:22:38 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/23 10:30:35 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int main()
{
	int a;
	int b;
	
	a=10;
	b=2;
	int c;
	int d;
	ft_div_mod(a, b, &c, &d);
	printf ("%d\n", a);
	printf ("%d\n", b);
	printf ("%d\n", c);
	printf ("%d\n", d);
}
*/