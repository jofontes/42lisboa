#include <stdio.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	int i;
	int j;
	i = 0;

	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}


// int main() {
//     const char *str1 = "abc123";
//     const char *str2 = "123";
    
//     size_t result = ft_strcspn(str1, str2);
//     printf("Resultado: %zu\n", result); // Resultado: 3
//     return 0;
// }











// Indexes
// // Needed for size_t
// #include <stdio.h>

// size_t ft_strcspn(const char *s, const char *reject)
// {
//     size_t i;
//     size_t j;
    
//     i = 0;
//     // Looping over the whole string
//     while(s[i++])
//     {
//         j = 0;
//         // Check the current string char against every char in charset
//         while (reject[j])
//         {
//             // If character found, return index in current string
//             if (s[i] == reject[j++])
//             	return (i);
//         }
//     }
//     // If we spanned the whole string, return i, in that case the
//     // rejected char found is the NULL-terminating one
//     return (i);
// }






// Pointers
// #include <stdio.h>

// size_t ft_strcspn(const char *s, const char *reject)
// {
//     // Save a pointer to the start of s
//     const char *og = s;
//     const char *s2;
    
//     // Looping over the whole string 
//     while (*s++)
//     {
//         // Set s2 to be the start of reject
//         // that way we keep the reject pointer to its original position
//         // Then loop over the whole charset
//         s2 = reject;
//         while (*s2)
//         {
//             // If current string charcter found in charset, return the
//             // number of characters spanned
//             if (*s == *s2++)
//                 // Here we make use of the original pointer to calculate
//                 // the number of char. spanned
//                 return (s - og);
//         }
//     }
//     // Same as above, we use the original pointer to calculate the number
//     // of character spanned
//     return (s - og);
// }







