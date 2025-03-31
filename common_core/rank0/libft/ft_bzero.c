/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:13:53 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/14 12:16:37 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The bzero function places nbyte null bytes in the string s

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}

/*
int main()
{
    char str[50];
    ft_bzero(str, sizeof(str));
    int i = 0;
    while (i < sizeof(str))
    {
        printf("%d ", str[i]);
        i++;
    }
    return 0;
}
*/
