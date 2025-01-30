#include <stdlib.h>


char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = 0;

	while(src[len])
		len++;
	dest = malloc(sizeof(char) + (len + 1));
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// int main()
// {
// 	char str[] = "hello";
// 	printf("%s", ft_strdup(str));
// }


















// #include <stdlib.h>

// char    *ft_strdup(char *src)
// {
// 	char	*tmp; //we will duplicate str into this variable
// 	int	len; 
// 	int	i;

// 	len = 0;
// 	i = 0;
// 	while (src[len]) //we calculate the length of src to create a place with enough memory
// 		len++;
// 	tmp = malloc(sizeof(char) * len + 1); //we allocate some space thanks to malloc. + 1 because the string need some space for the extra "\0" at the end (don't forget it !)
// 	if (!tmp) //malloc protection
// 		return (NULL);
// 	while (src[i]) //loop to complete the new string
// 	{
// 		tmp[i] = src[i];
// 		i++;
// 	}
// 	tmp[i] = 0; //adding the null character at the end
// 	return (tmp);
// }


// #include <stdio.h>

// int main()
// {
// 	char	*a;
// 	a = "Hello World";
// 	printf("%s\n", ft_strdup(a));
// }