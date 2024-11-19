/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:09:01 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/07 22:06:52 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	h[10];
	int	i;
	int	temp;

	i = 0;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
		write(1, &"-", 1);
	while (nb != 0)
	{
		temp = nb % 10;
		if (temp < 0)
			temp = temp * (-1);
		h[i] = temp;
		i++;
		nb = nb / 10;
	}
	while (--i > -1)
		ft_putchar(h[i] + '0');
}
/*
int main()
{
	int nb;
	nb = -2147483647;
	ft_putnbr(nb);
}
*/