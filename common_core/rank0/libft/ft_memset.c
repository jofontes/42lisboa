/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:52:42 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/14 12:30:20 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the memset() function in C is used to set memory locations to a specific value

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

/*
int main()
{
    char str[50];

    ft_memset(str, 'A', sizeof(str) - 1);
    //str[49] = '\0';
    printf("%s\n", str); 
    return 0;
}
*/
