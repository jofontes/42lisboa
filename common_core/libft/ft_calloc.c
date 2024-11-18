/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:38:41 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/14 13:38:29 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Aloca um posicao de memoria. coloca tudo a zero e retorna essa posicao

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, nmemb * size);
	return (dest);
}
