/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:15:40 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/14 12:30:34 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// aloca memoria e retorna uma nova string
// essa string resulta da concatenacao de s1 e s2
// retorna a nova string, NULL se a alocacao falhar

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

// int main()
// {
// 	char s1[] = "lorem ipsum";
// 	char s2[] = "dolor sit amet";
// 	printf("%s", ft_strjoin(s1, s2));	
// }
