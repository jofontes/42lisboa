#include <unistd.h>


int main(int argc, char **argv)
{
	int i;
	i = 0;
	int j;

	if (argc == 2)
	{
		while(argv[1][i])
		{
			if('a' <= argv[1][i] && argv[1][i] <= 'z')
			{
				j = argv[1][i] - 97;
				while(j != -1)
				{
					write(1, &argv[1][i], 1);
					j--;
				}
			}
			if('A' <= argv[1][i] && argv[1][i] <= 'Z')
			{
				j = argv[1][i] - 65;
				while(j != -1)
				{
					write(1, &argv[1][i], 1);
					j--;
				}
			}
			
			
			i++;
		}
	}
	write(1, "\n", 1);
}


