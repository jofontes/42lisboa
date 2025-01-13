#include <unistd.h>




int main()
{
	int i;
	int j;
	int k;
	i = 1;

	char num;
	char num2;

	while (i < 20)
	{
		j = i;
		if(j>10)
		{
			num = j%10 + '0';
			write(1, &num, 1);
			j/=10;
		}
		num = j + '0';
		write(1, &num, 1);
		write(1, "\n", 1);
		i++;
	}

}