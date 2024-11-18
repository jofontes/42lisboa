/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:53:35 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/14 12:23:52 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// retorna um array de novas strings resultadas do split
// retorna null se alocacao falhar

#include "libft.h"

static	char	**free_all(char **dest, int counter)
{
	while (counter-- > 0)
		free(dest[counter]);
	free(dest);
	return (NULL);
}

static	int	count_words(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		counter++;
	}
	return (counter);
}

static	char	**split(char const *s, char c, char **dest, int counter)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		dest[counter] = malloc(sizeof(char) * (i - j + 1));
		if (!dest[counter])
		{
			free_all(dest, counter);
			return (NULL);
		}
		ft_strlcpy(dest[counter], &s[j], (i - j + 1));
		counter++;
	}
	dest[counter] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		counter;

	counter = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	dest = split(s, c, dest, counter);
	return (dest);
}

// int main()
// {
// 	char *str = "    ";
// 	char c = ' ';
// 	char **dest = ft_split(str, c);
// 	while(*dest)
// 		printf("%s ", *dest++);
// 	free(dest);
// }
