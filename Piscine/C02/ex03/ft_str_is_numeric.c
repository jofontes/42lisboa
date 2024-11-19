/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:31:43 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/02 10:09:04 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/*
int main()
{
	printf("%d", ft_str_is_numeric("12345"));
	printf("\n%d", ft_str_is_numeric("1234v"));
	printf("\n%d", ft_str_is_numeric("abc"));
	printf("\n%d", ft_str_is_numeric(""));
}
*/