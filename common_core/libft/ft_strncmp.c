/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:39:16 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/12 11:02:58 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strcmp() function compares the two strings s1 and s2
// Retorna a diferenca
// The strncmp() only compares the first n bytes of s1 and s2. 

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	printf("%d", ft_strncmp("abcd", "abcd", 3));
	printf("\n%d", ft_strncmp("aacd", "abcd", 3));
	printf("\n%d", ft_strncmp("dacd", "abcd", 3));
	
}
*/