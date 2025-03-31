/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:19:20 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/12 11:02:53 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// aplica a funcao f a cada carctere da string s
// retorna a string com as alteracoes feitas pela funcao f

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	i = 0;
	if (!s || !f)
		return (NULL);
	dest = malloc (ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// char	to_upper(unsigned int i, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 	{
// 		return (c - 32);
// 	}
// 	return (c);
// }

// int main()
// {
// 	char *s = "hello world";
// 	printf ("%s", ft_strmapi(s, to_upper));
// }
