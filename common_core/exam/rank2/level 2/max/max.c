

int	max(int* tab, unsigned int len)
{
	int temp;
	int i;
	temp = 0;
	i = 0;
	while(i < len)
	{
		if (tab[i] > temp)
			temp = tab[i];
		i++;
	}
	return (temp);
	
}

#include <stdio.h>

int main()
{
	int int_tab[] = {1, 3, 2, 10, 9};
	printf("%d", max(int_tab, 5));
}





// int		max(int* tab, unsigned int len)
// {
// 	int count = 0;
// 	int result = 0;
// 	int i = 0;
// 	if (len > 0)
// 	{
// 		while (count < len)
// 		{
// 			if (tab[i] > result)
// 				result = tab[i];
// 			i++;
// 			count++;
// 		}
// 		return (result);
// 	}
// 	return (0);
// }

// #include <stdio.h>

// int main()
// {
// 	int int_tab[] = {1, 3, 2, 10, 9};
// 	printf("%d", max(int_tab, 5));
// }