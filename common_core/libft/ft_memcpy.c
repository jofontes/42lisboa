/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:17:30 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/14 12:30:05 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This function copies n bytes from src into dest
//It doesnt take care of overlaping memory
//It returns a pointer to n the start of dest

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*new;
	const unsigned char	*old;
	size_t				i;

	i = 0;
	new = dest;
	old = src;
	if (new == old || n == 0)
		return (dest);
	while (i < n)
	{
		new[i] = old[i];
		i++;
	}
	return (dest);
}
