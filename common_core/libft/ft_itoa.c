/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:33:14 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/12 11:00:31 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// aloca memoria e retorna uma string que representa o n
// numeros negativos tem de ser tratados
// retorna a string do int n, NULL se alocacao falhar

#include "libft.h"

static	int	ft_n_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		n_len;
	long	n_long;
	char	*dest;

	n_long = n;
	n_len = ft_n_len(n_long);
	dest = malloc(sizeof(char) * (n_len + 1));
	if (!dest)
		return (NULL);
	dest[n_len] = '\0';
	if (n_long == 0)
		dest[n_len - 1] = '0';
	if (n_long < 0)
	{
		n_long *= -1;
		dest[0] = '-';
	}
	while (n_long != 0)
	{
		dest[n_len - 1] = (n_long % 10) + '0';
		n_len--;
		n_long = n_long / 10;
	}
	return (dest);
}

// int main()
// {
// 	int n = 123;
// 	printf("%s", ft_itoa(n));
// }
