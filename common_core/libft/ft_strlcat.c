/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:02:08 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/13 14:32:28 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//concatenar strings e retorna strlen do dest + src

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			src_len;
	size_t			dest_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (src_len + size);
	i = dest_len;
	j = 0;
	while (i < size - 1 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (src_len + dest_len);
}

/*
int main ()
{
	char src[]=" World";
	char dest[]="Hello";
	int size;
	size = 3;
	
	printf("%zu", ft_strlcat(dest, src, size));
}
*/
