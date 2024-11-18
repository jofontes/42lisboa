/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:38:49 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/12 11:00:36 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function searches for the char c in the memory
// It returns a pointer to the first char in finds

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char s[] = "test string";
// 	printf("%s\n", (char *)ft_memchr(s, 's', 5));
// 	return (0);
// }