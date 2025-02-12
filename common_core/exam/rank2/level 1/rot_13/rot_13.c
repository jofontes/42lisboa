#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int j;
		char temp;
		while (av[1][i])
		{
			temp = av[1][i];
			j = 0;
			if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
			{
				while (j < 13)
				{
					if (temp == 'z')
					{
						temp = 'a';
						j++;
					}
					else if (temp == 'Z')
					{
						temp = 'A';
						j++;
					}
					else
					{
						temp = temp + 1;
						j++;
					}
					
				}
			}	
			write(1, &temp, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

/*
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
*/


