/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:40:46 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/12 11:01:20 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// output a int n com o fd dado

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	h[10];
	int	i;
	int	temp;

	i = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (n != 0)
	{
		temp = n % 10;
		if (temp < 0)
			temp = temp * (-1);
		h[i] = temp;
		i++;
		n = n / 10;
	}
	while (--i > -1)
		ft_putchar_fd(h[i] + '0', fd);
}

// int main()
// {
// 	int nb;
// 	nb = -2147483647;
// 	ft_putnbr_fd(nb);
// }
