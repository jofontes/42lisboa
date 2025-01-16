#include <unistd.h>


int main(int ac, char **av)
{
	int i;
	i = 0;
	char temp;
	int j;
	
	if(ac == 2)
	{
		while (av[1][i])
		{
			j = 13;
			temp = av[1][i];
			while(j > 0)
			{
				if(temp == 'z')
					temp = 'm';
				temp = temp + 1;
				j--;
			}
			
			write(1, &temp, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

