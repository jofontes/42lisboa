#include <stdio.h>

int ft_atoi(const char *str)
{
	int i;
	int neg;
	int result;

	i = 0;
	neg = 1;
	result = 0;

	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if(str[i] == '+')
		i++;
	else if(str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result *neg);
}

// int main()
// {
// 	printf("%d", ft_atoi("    +1234"));
// }









// /* this function returns 1 if the character is one 
//  * of the "space" character or 0 if it is not
//  */
// int ft_isspace(int c)
// {
//     return ((c >= 9 && c <= 13) || c == 32 ? 1 : 0);
// }

// /* this function returns 1 if the character is a digit 0-9
//  * and 0 if the character is not a digit 0-9
//  */
// int ft_isdigit(int c)
// {
//     return (c >= 48 && c <= 57 ? 1 : 0);
// }

// int ft_atoi(const char *str)
// {
//     int res = 0;
//     int i = 0;
//     int s = 1;
    
//     /* skipping all the space characters 
//     */
//     while (ft_isspace(str[i]))
//         i++;
//     /* if there is a - we set the sign to -1 and we go to
//      * the next character
//      */
//     if (str[i] == '-')
//     {
//         s = -1;
//         i++;
//     }
//     /* while the number is a digit, we convert it to an int
//      */
//     while (ft_isdigit(str[i]))
//     {
//         res *= 10;
//         res += str[i] - 48;
//         i++;
//     }
//     /* at the end, we multiply the number by the sign variable
//      * and we finally return the int number
//      */
//     return (res *= s);
// }