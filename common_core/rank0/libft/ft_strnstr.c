/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:39:20 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/13 14:48:31 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This function searches n bytes of the string for the string to find
//It returns a pointer to he found string or null if didnt found

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	if (!len)
		return (NULL);
	while (big[i] != '\0' && len > i)
	{
		while (little[j] != '\0' && big[i + j] == little[j] && len > i + j)
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
		j = 0;
	}
	return (NULL);
}

/*
int main()
{
	char big[] = "sport lisboa benfica o melhor";
	char little[] = "lisboa";
	printf("%s", ft_strnstr(big, little, 30));
	return (0);
}
*/
