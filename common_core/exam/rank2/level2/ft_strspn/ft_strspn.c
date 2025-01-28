#include <stdlib.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int i;
	int	j;
	int check;

	i = 0;
	while (s[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (i);
		i++;
	}
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	char *s = "hello";
// 	const char *accept = "jfkhpell";
// 	printf("%zu\n", ft_strspn(s, accept));
// }