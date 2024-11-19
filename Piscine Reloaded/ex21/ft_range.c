/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:14:26 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/24 14:57:46 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	i = 0;
	result = malloc(sizeof(int) * ((max - min) + 1));
	if ((max - min) == 0)
		return (0);
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (result);
}

/*
int main()
{
	int min;
	int max;
	int *result;
	min = 0;
	max = 5;
	//printf("array: %d", *ft_range(min, max));
	result = ft_range(min, max);
	int i;
	i = 0;
	while (i < (max-min))
	{
		printf("%d", result[i]);
		i++;
	}
	
}
*/
