/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:36:26 by josaraiv          #+#    #+#             */
/*   Updated: 2024/09/30 10:35:11 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
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
	printf("%d", ft_str_is_lowercase("abcd"));
	printf("\n%d", ft_str_is_lowercase("abcD"));
	printf("\n%d", ft_str_is_lowercase("ab1c"));
	printf("\n%d", ft_str_is_lowercase(""));
	
}
*/