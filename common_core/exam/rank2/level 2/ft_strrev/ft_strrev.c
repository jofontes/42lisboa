/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:09:47 by josaraiv          #+#    #+#             */
/*   Updated: 2025/01/29 17:31:18 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	*ft_strrev(char *str)
{
	int i;
	int len;
	char temp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while(i < len - 1)
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		i++;
		len--;
	}
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char s[] = "Hello World";
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}