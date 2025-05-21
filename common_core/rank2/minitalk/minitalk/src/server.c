#include "../inc/minitalk.h"

int	putchar(int c)
{
	return (write(1, &c, 1));
}

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
	{
		return (putchar(symbols[n]));
	}
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}


void	sig_handler(int sig)
{
	static int	bit;
	static int	i; 

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8) 
	{
		putchar(i); 
		bit = 0; 
		i = 0; 
	}
}

int	main(int argc, char **argv) 
{
	pid_t	pid;

	(void)argv; 
	if (argc != 1) 
	{
		write(1, "Error: wrong format\n", 20);
		write(1, "Try: ./server\n", 14);
	}
	pid = getpid(); 
	write(1, "PID:", 4); // %d\n", pid);
	print_digit(pid, 10); 
	write(1, "\nWaiting for a message...\n", 26);
	while (argc == 1)
	{
		signal(SIGUSR1, sig_handler); 
		signal(SIGUSR2, sig_handler); 
		pause();
	}
	return (0); 
}

