/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:04:02 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/08 15:02:24 by josaraiv         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (nb >= 2)
	{
		if (ft_is_prime (nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}
/*
int main(void)
{
	printf("%d", ft_find_next_prime(50));

}
*/