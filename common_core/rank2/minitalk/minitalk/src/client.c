#include "../inc/minitalk.h"

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
		neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * neg);
}


void	send_bits(pid_t pid, char c)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int main(int argc, char **argv)
{
	pid_t pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]); 
		msg = argv[2]; 
		while (*msg != '\0') 
		{
			send_bits(pid, *msg); 
			msg++; 
		}
		send_bits(pid, '\n'); 
	}
	else
	{
		write(1, "Error: wrong format\n", 20);
		write(1, "Try: ./client <PID> <MESSAGE>\n", 30);
		return (1); 
	}
	return (0);
}