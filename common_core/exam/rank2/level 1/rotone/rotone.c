#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	i = 0;
	char temp;
	if(ac == 2)
	{
		while(av[1][i])
		{
			temp = av[1][i];
			if (temp == 'z')
			{
				temp = 'a';
				write(1, &temp, 1);
			}
			else if (temp == 'Z')
			{
				temp = 'A';
				write(1, &temp, 1);
			}
			else if ((temp >= 'a' && temp <= 'y') || (temp >= 'A' && temp <= 'Y') )
			{	
				temp = temp + 1;
				write(1, &temp, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}




