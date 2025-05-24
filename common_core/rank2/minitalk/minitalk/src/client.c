/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:40:26 by josaraiv          #+#    #+#             */
/*   Updated: 2025/05/23 18:41:45 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

bool	g_ack_received = 0;

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	return (result * neg);
}

void	handle_ack(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack_received)
			pause();
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
	{
		write(2, "Error: wrong format\n", 20);
		write(2, "Try: ./client <PID> <MESSAGE>\n", 30);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0 || kill(pid, 0) == -1)
		return (write(2, "check your pid \n", 16));
	signal(SIGUSR1, handle_ack);
	msg = argv[2];
	while (*msg)
		send_bits(pid, *msg++);
	write(1, "Sent! :)\n", 9);
	return (0);
}
