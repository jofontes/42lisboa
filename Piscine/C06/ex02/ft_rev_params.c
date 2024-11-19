/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:16:56 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/09 11:26:27 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	count;

	count = ac - 1;
	while (count > 0)
	{
		i = 0;
		while (av[count][i] != '\0')
		{
			write(1, &av[count][i], 1);
			i++;
		}
		write(1, "\n", 1);
		count--;
	}
}
