#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av)
{
	if (ac == 3)
	{
		int n1 = atoi(av[1]);
		int n2 = atoi(av[2]);

		int i = 1;
		int dem = 1;
		while (i <= n2)
		{
			if ((n1 % i == 0) && (n2 % i == 0))
				dem = i;
			i++;
		}
		printf("%d", dem);
	}
	printf("\n");
}






/*
int main(int ac, char **av)
{
	if (ac == 3)
	{
		int min;
		int n1 = atoi(av[1]);
		int n2 = atoi(av[2]);
		if (n1 > n2)
			min = n2;
		else
			min = n1;
		while (min > 0)
		{
			if (n1 % min == 0 && n2 % min == 0)
			{
				printf("%d", min);
				break;
			}
			min--;
		}
	}
	printf("\n");
	return (0);
}
*/




















// #include <stdio.h>
// #include <stdlib.h>

// int main(int ac, char **av)
// {

//     if (ac == 3)
//     {
//         // I won't explain the whole thing
// 	// but if we take 14 and 77 as input we would
// 	// have the following (each iteration separated by ;)
// 	// 14; 14; 14; 14; 14; 14; 7
// 	// 77; 63; 49; 35; 21; 7;  7
//         int number1 = atoi(av[1]);
//         int number2 = atoi(av[2]);
        
//         if (number1 > 0 && number2 > 0)
//         {
//             while (number1 != number2)
//             {
//                 if (number1 > number2)
//                     number1 = number1 - number2;
//                 else
//                     number2 = number2 - number1;
//             }
//             printf("%d", number1);
//         }
//     }
//     printf("\n");
// }
