/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:33 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/14 12:30:53 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Retorna uma string da string original(s)
// Comeca no start(posicao de inicio) e copia o numero len de caracteres

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		s_len;
	char		*dest;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (start + len >= s_len)
		len = ft_strlen(s) - start;
	dest = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int	main()
{
	char	s[] = "hello";
	int start = 2;
	int len = 2;
	printf("%s", ft_substr(s, start, len));
}
*/
