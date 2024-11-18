/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:09:17 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/13 12:50:53 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copiar string e retorna o strlen da source

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while ((i < (size - 1)) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

/*
int main()
{
	char src[] = "Hello World";
	char dest[50];
	printf("%zu", ft_strlcpy(dest, src,20));
}
*/
