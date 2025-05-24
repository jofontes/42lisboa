/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:42:00 by josaraiv          #+#    #+#             */
/*   Updated: 2025/05/23 18:42:20 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	putchar(int c)
{
	return (write(1, &c, 1));
}

int	print_digit(long n, int base)
{
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	if (n < 0)
		return (write(1, "-", 1) + print_digit(-n, base));
	if (n < base)
		return (putchar(symbols[n]));
	count = print_digit(n / base, base);
	return (count + print_digit(n % base, base));
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	char_accum = 0;

	(void)context;
	if (sig == SIGUSR1)
		char_accum |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &char_accum, 1);
		bit = 0;
		char_accum = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	write(1, "PID: ", 5);
	print_digit(pid, 10);
	write(1, "\nWaiting for a message...\n", 26);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
