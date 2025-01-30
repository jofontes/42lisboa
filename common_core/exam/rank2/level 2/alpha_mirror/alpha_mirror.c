#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	i = 0;
	if (ac == 2)
	{
		while(av[1][i])
		{
			if (av[1][i] >= 65 && av[1][i] <= 90)
				av[1][i] = 90 - av[1][i] + 65;
			else if (av[1][i] >= 97 && av[1][i] <= 122)
				av[1][i] = 122 - av[1][i] + 97;
			write(1, &av[1][i], 1);	
			i++;
		}
	}
	write(1, "\n", 1);
}




// #include <unistd.h>

// int main(int ac, char *av[])
// {
//     int i;
    
//     if (ac == 2)
//     {
//         i = 0;
//         while (av[1][i])
//         {
//             if (av[1][i] >= 65 && av[1][i] <= 90)
//             /* we remove the ASCII code of the letter from the ASCII
//              * code of the last upper-case letter, then add the ASCII
//              * code of the first upper-case letter
//              * 90 - 65(A) = 35, 35 + 65 = 90(Z)
//              * 90 - 66(B) = 34, 34 + 65 = 89(Y)
//              */ 
//                 av[1][i] = 90 - av[1][i] + 65;
//             else if (av[1][i] >= 97 && av[1][i] <= 122)
//             /* we remove the ASCII code of the letter from the ASCII
//              * code of the last lower-case letter, then add the ASCII
//              * code of the first lower-case letter
//              * 122 - 97(a) = 35, 35 + 97 = 122(z)
//              * 122 - 98(b) = 34, 34 + 97 = 121(y)
//              */ 
//                 av[1][i] = 122 - av[1][i] + 97;
//             /* finally, we can writethe current character to the screen
//              */
//             write(1, &av[1][i], 1);
//             i++;
//         }
//     }
//     write(1, "\n", 1);
// }

