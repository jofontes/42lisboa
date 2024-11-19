/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:45:10 by josaraiv          #+#    #+#             */
/*   Updated: 2024/09/30 10:31:15 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if ((97 <= str[i] && str[i] <= 122) || (65 <= str[i] && str[i] <= 90))
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
int main ()
{
	
	printf("%d", ft_str_is_alpha("teste"));
	printf("\n%d", ft_str_is_alpha("teSte"));
	printf("\n%d", ft_str_is_alpha("12345"));
	printf("\n%d", ft_str_is_alpha(""));
	
}
*/