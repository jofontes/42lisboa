/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:16:52 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/10/09 14:49:08 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*dikchi(void);
void	ft_putstr(char *str);

int	ft_is_valid(int i, char *av)
{
	while (*av)
	{
		while ((av[i] >= 9 && av[i] <= 13) || av[i] == 32)
			i++;
		if ((av[i] == '+' || av[i] == '-') && (av[i + 1] == '+'
				|| av[i + 1] == '-'))
		{
			write (1, "0/n", 2);
			break ;
		}
		else if (av[i] == '-')
		{
			write (1, "Error\n", 6);
			break ;
		}
		while (av[i] < '0' || av[i] > '9')
			i++;
		return (i);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] >= '0' && str[size] <= '9')
		size++;
	return (size);
}

char	*ft_strcpy(int i, int j, char *av)
{
	char	*numdest;
	int		size;

	size = ft_strlen(av);
	numdest = (char *)malloc(sizeof(char) * (size + 1));
	while (av[i] >= '0' && av[i] <= '9')
	{
		numdest[j] = av[i];
		j++;
		i++;
	}
	numdest[j] = '\0';
	return (numdest);
}

int	main(int ac, char **av)
{
	int		count;
	int		i;
	int		j;
	char	*numdest;

	count = 0;
	j = 0;
	if (ac == 2)
		count = 1;
	else if (ac == 3)
		count = 2;
	i = ft_is_valid(j, av[count]);
	numdest = ft_strcpy(i, j, av[count]);
	ft_putstr(dikchi());
}
