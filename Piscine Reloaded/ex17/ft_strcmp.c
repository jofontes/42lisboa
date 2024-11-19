/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:01:52 by josaraiv          #+#    #+#             */
/*   Updated: 2024/10/23 11:08:37 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	cmp;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			return (cmp);
		}
		i++;
	}
	return (0);
}

/*
int main()
{
	printf("%d", ft_strcmp("abcd", "abcd"));
	printf("\n%d", ft_strcmp("abcd", "abce"));
	printf("\n%d", ft_strcmp("abce", "abcd"));
}
*/
