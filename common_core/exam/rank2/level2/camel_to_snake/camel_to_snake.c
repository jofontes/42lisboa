#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i;
	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if(av[1][i] >= 65 && av[1][i] <= 90)
			{
				av[1][i] += 32;
				write(1, "_", 1);
			}
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}






// #include <unistd.h>

// int main(int ac, char *av[])
// {
//     int i;
    
//     if (ac == 2)
//     {
//         i = 0;
//         /* looping over the whole string
//          */
//         while (av[1][i])
//         {
//             /* if we encounter an upper-case letter
//              * we have to make it lower-case and write a _ before it
//              */
//             if (av[1][i] >= 65 && av[1][i] <= 90)
//             {
//                 /* here, we change the upper-case letter to its
//                  * corresponding lower-case letter
//                  */
//                 av[1][i] += 32;
//                 /* we write a _ to the screen
//                  */
//                 write(1, "_", 1);
//             }
//             /* then we can write the current character, changed or not
//              */
//             write(1, &av[1][i], 1);
//             i++;
//         }
//     }
//     /* finally we can write the newline
//      */
//     write(1, "\n", 1);
// }