#include <unistd.h>














int main(int ac, char **av)
{
    if( ac == 2)
    {
        int i;
        i = 0;
        int space;
        space = 0;

        while (av[1][i] <= 32)
            i++;
        while (av[1][i])
        {
            // while (av[1][i] <= 32)
            //     i++;
            if (av[1][i] <= 32)
            {
               if (space == 0)
               {
                    write(1, " ", 1);
                    space = 1;
               }
            }
            else
            {
                write(1, &av[1][i], 1);
                space = 0;
            }
            i++;
        }
    }
    write(1,"\n", 1);
}













// #include <unistd.h>

// void ft_putchar(char c)
// {
//     write(1, &c, 1);
// }

// int is_space(char c)
// {
//     if (c <= 32)
//         return 1;
//     return 0;
// }   

// int main(int ac, char **av)
// {
//     if (ac == 2)
//     {
//         int i = 0, space = 0;
//         // skipping all leading blank chars
//         while (is_space(av[1][i]))
//             i++;
//         while (av[1][i])
//         {
//             // if there is a blank char, make the space flag 1
//             // if there are multiple blank, it will be set
//             // to 1 each time
//             if (is_space(av[1][i]))
//                 space = 1;
//             // if current char is not a blank char
//             // write a space if flag is on
//             // set the space flag back to 0
//             // write current char
//             if (!is_space(av[1][i]))
//             {
//                 if (space)
//                     ft_putchar(' ');
//                 space = 0;
//                 ft_putchar(av[1][i]);
//             }
//             i++;
//         }
//     }
//     ft_putchar('\n');
// }