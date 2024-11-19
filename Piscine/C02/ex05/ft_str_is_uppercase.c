/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:00:24 by josaraiv          #+#    #+#             */
/*   Updated: 2024/09/30 10:38:00 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str [i] != '\0' )
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
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
	printf("%d", ft_str_is_uppercase("ABCD"));
	printf("\n%d", ft_str_is_uppercase("abcd"));
	printf("\n%d", ft_str_is_uppercase("AbCd"));
	printf("\n%d", ft_str_is_uppercase("1234"));
	printf("\n%d", ft_str_is_uppercase(""));
}
*/