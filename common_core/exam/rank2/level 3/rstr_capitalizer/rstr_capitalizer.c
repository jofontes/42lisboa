#include <unistd.h>



int main(int ac, char **av)
{
	int i;
	int j;
	j = 1;

	while (ac > 1)
	{
		i = 0;
		while(av[j][i])
		{
			if (av[j][i] >= 'A' && av[j][i] <= 'Z')
				av[j][i] += 32;
			if ((av[j][i] >= 'a' && av[j][i] <= 'z') && av[j][i+1] <= 32)
				av[j][i] -= 32;
			write(1, &av[j][i], 1);
			i++;
			
		}
		j++;
		ac--;
		if (ac > 1)
			write (1, "\n", 1);
	}
	if (ac == 1)
		write (1, "\n", 1);
}











// #include <unistd.h>

// int ft_isspace(char c)
// {
//     if (c <= 32)
//         return (1);
//     return (0);
// }

// void ft_putchar(char c)
// {
//     write(1, &c, 1);
// }

// void r_capitalizer(char *s)
// {
//     int i = 0;
//     while (s[i])
//     {
//          // If the character is uppercase, make it lowercase
//          if (s[i] >= 'A' && s[i] <= 'Z')
//              s[i] += 32;
//          // Now check for lowercase character and if the next char
//          // is a space character, make it uppercase again
//          if ((s[i] >= 'a' && s[i] <= 'z') && ft_isspace(s[i + 1]))
//              s[i] -= 32;
//          // Now print every char
//          ft_putchar(s[i++]);
//     }
// }

// int main(int ac, char **av)
// {
//     int i = 1;
//     if (ac == 1)
//         ft_putchar('\n');
//     else
//     {
//         // Loop over all params starting at 1 (we don't want the name of
//         // the executable to be written to the screen)
//         while (i < ac)
//         {
//             r_capitalizer(av[i]);
//             ft_putchar('\n');
//             i++;
//         } 
//     }
// }