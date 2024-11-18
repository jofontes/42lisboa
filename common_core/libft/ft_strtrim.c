/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:13:25 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/14 12:30:49 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//aloca memoria e retorna uma copia de s1
//remove os caracteres especificados em set na string no incio e fim

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	len = j - i;
	return (ft_substr(s1, i, len));
}

/*
int main()
{
	char s1[] = "abtesteab";
	char set[] = "ab";
	printf("%s", ft_strtrim(s1, set));
}
*/