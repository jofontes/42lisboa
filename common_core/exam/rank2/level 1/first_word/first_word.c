#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int count;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] == 32 || argv[1][i] == 9)
			i++;
		while (argv[1][i] != '\0' && argv[1][i] != 32 && argv[1][i] != 9)
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	
	}

	write(1, "\n", 1);
	
}

