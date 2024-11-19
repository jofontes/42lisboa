/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:00:09 by josaraiv          #+#    #+#             */
/*   Updated: 2024/09/28 18:07:54 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size - i - 1)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}
/*
int main()
{
	int size = 4;
	int i = 0;
	int	array[] = {5, 10, 15, 20};
	ft_rev_int_tab(array, size);

	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	
	
}
*/