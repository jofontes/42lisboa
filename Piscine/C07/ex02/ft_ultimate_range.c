/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:08:07 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/10 00:28:07 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*result;

	i = 0;
	result = malloc(sizeof(int) * ((max - min) + 1));
	if ((max - min) == 0)
		return (0);
	*range = result;
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (i);
}

/*
int main()
{
	int min;
	int max;
	int size;
	int *range;
	min = 5;
	max = 10;
	
	size = ft_ultimate_range(&range, min, max);
	int i;
	i = 0;
	while (i < (max-min))
	{
		printf("%d ", range[i]);
		i++;
	}
}
*/