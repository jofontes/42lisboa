/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:50:48 by josaraiv          #+#    #+#             */
/*   Updated: 2024/12/09 15:23:54 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *next_line, char *buffer)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*dest;

	s1_len = ft_strlen(next_line);
	s2_len = ft_strlen(buffer);
	dest = malloc(s1_len + s2_len + 1);
	if (!dest)
		return (free(next_line), NULL);
	dest[s1_len + s2_len] = '\0';
	i = -1;
	while (++i < s1_len)
		dest[i] = next_line[i];
	free(next_line);
	i = -1;
	while (++i < s2_len)
		dest[s1_len + i] = buffer[i];
	i = -1;
	while (buffer[s2_len + ++i])
		buffer[i] = buffer[s2_len + i];
	buffer[i] = '\0';
	return (dest);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		len1;
// 	int		len2;
// 	int		i;
// 	char	*result;

// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	result = malloc(len1 + len2 + 1);
// 	if (!result)
// 		return (free(s1), NULL);
// 	result[len1 + len2] = '\0';
// 	i = -1;
// 	while (++i < len1)
// 		result[i] = s1[i];
// 	i = -1;
// 	while (++i < len2)
// 		result[len1 + i] = s2[i];
// 	free(s1);
// 	i = -1;
// 	while (s2[len2 + ++i])
// 	{
// 		s2[i] = s2[len2 + i];
// 	}
// 	s2[i] = '\0';
// 	return (result);
// }

// char *ft_strjoin(char *next_line, char *buffer)
// {
// 	int i;
// 	int j;
// 	int s1_len;
// 	int s2_len;
// 	char *dest;

// 	s1_len = ft_strlen(next_line);
// 	s2_len = ft_strlen(buffer);
// 	i = -1;
// 	j = 0;
// 	dest = malloc(s1_len + s2_len + 1);
// 	if(!dest)
// 		return (NULL);
// 	while(++i < s1_len)
// 		dest[i] = next_line[i];
// 	while(j < s2_len)
// 		dest[i++] = buffer[j++];
// 	j = 0;
// 	while (buffer[j])
// 		buffer[j++] = buffer[--s2_len];
// 	buffer[j] = '\0';
// 	dest[i] = '\0';
// 	free(next_line);
// 	return (dest);
// }