/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:54:53 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/14 12:23:26 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This function copies n bytes from src into dest
//It take care of overlaping memory
//It returns a pointer to n the start of dest

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*new;
	const unsigned char	*old;
	size_t				i;

	new = dest;
	old = src;
	if (new < old)
	{
		i = 0;
		while (i < n)
		{
			new[i] = old[i];
			i++;
		}
	}
	else if (new > old)
	{
		i = n;
		while (i > 0)
		{
			new[i - 1] = old[i - 1];
			i--;
		}
	}
	return (dest);
}

/*
int main() {
    char str[] = "Hello, World!";
    printf("Original: %s\n", str);
    // Copiando uma parte da string para uma posição que se sobrepõe
    ft_memmove(str + 7, str, 6); // Copia "Hello," para "World!"
    printf("Após ft_memmove: %s\n", str); //"Hello, Hello, World!"
    return 0;
}
*/
