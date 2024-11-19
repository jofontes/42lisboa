/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:15 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/08 14:48:47 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < nb)
	{
		if (nb % i == 0)
			j++;
		i++;
	}
	if (j == 1)
		return (1);
	return (0);
}
/*
int main()
{
	printf("%d", ft_is_prime(5));
}
*/