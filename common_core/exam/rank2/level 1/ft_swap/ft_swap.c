#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// int main()
// {
// 	int a;
// 	int b;

// 	a=1;
// 	b=2;
// 	printf("a = %d\n", a);
// 	printf("b = %d\n", b);
// 	ft_swap(&a,&b);
// 	printf("a = %d\n", a);
// 	printf("b = %d\n", b);
// }