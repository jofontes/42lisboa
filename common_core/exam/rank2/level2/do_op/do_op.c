#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		switch (av[2][0])
		{
			case '+':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '-':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '*':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '/':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '%':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			
			
		}	
	}


	printf("\n");
}













// #include <stdio.h>
// #include <stdlib.h>

// int main(int ac, char *av[])
// {
//     /* checking the number of arguments
//      */
//     if (ac == 4)
//     {
//         /* we then switch over the operator (av[2][0])
//          */
//         switch(av[2][0])
//         {
//             /* if the operator is + we simply make an
//              * addition and print the result to the screen
//              */
//             case '+':
//                 printf("%d", atoi(av[1]) + atoi(av[3]));
//                 break;
//             /* if the operator is - we simply make a
//              * substraction and print the result to the screen
//              */
//             case '-':
//                 printf("%d", atoi(av[1]) - atoi(av[3]));
//                 break;
//             /* if the operator is * we simply make a
//              * multiplication and print the result to the screen
//              */
//             case '*':
//                 printf("%d", atoi(av[1]) * atoi(av[3]));
//                 break;
//             /* if the operator is / we simply make a
//              * divisions and print the result to the screen
//              */            
//             case '/':
//                 printf("%d", atoi(av[1]) / atoi(av[3]));
//                 break;
//             /* if the operator is % we simply make a
//              * modulo and print the result to the screen
//              */
//             case '%':
//                 printf("%d", atoi(av[1]) % atoi(av[3]));
//                 break;
//         }
//     }
//     /* finally, we write a newline
//      */
//     printf("\n");
// }