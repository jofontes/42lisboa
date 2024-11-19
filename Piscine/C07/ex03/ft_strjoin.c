/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:14:41 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/10 18:53:23 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_len(char *str)
{
	int i;
	i=0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	i = 0;
	int size_strs;
	int size_sep;
	int size_total;
	while(i < size)
	{
	
		size_strs += ft_len(strs);
		i++;
	}
	
	char *result;
	
	result = malloc(sizeof(char) * (size_strs + size_sep + 1));



}

int main()
{
	char **str = {"hello", "world"};	
	char *sep;
	sep = ","
	
	int	size;
	size = 2;
	
	printf("%s", ft_strjoin(size, str, sep));
}

int	main(int argc, char **argv)
{
	char	*sep;
	sep = ",";
	printf("%s", ft_strjoin(argc, argv, sep));
}*/