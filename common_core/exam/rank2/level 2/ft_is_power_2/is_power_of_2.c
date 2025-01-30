

int	is_power_of_2(unsigned int n)
{
	int i;
	i = 1;
	while (i < n)
	{
		i *=2;
	}
	if(i == n)
		return (1);
	return (0);
}



// #include <stdio.h>
// int main()
// {
// 	printf("%d", is_power_of_2(16));
// }









// int	    is_power_of_2(unsigned int n)
// {

// // we will initialize a test variable to 1, and we will multiply it by 2 until it is equal to or greater than the variable we have been given as a parameter (n). If the two variables are equal it means that it is a power of 2 (since we have always multiplied this number by 2)
	
// 	int test = 1;

// 	while (test <= n)
// 	{
// 		if (test == n)
// 			return  (1); // test is a power of 2
// 		test = test * 2;
// 	}
// 	// we will leave the loop if the test variable is greater than n. this means that it is not a power of 2 an we need to return 0.
// 	return (0);
// }


// #include <stdio.h>
// int main()
// {
// 	printf("%d", is_power_of_2(16));
// }