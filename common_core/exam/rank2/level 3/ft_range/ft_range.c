#include <stdlib.h>


int *ft_range(int start, int end)
{
    int i = 0;
    int len = end - start;
    if (len < 0)
    {
        len *= -1;
        len += 1;
    }
    else if (len > 0)
    {
        len += 1;
    }

    int *range;
    range = (int *) malloc(sizeof(int) * len);
    while (i < len)
    {
        if (start < end)
            range[i] = start++;
        else
            range[i] = start--;
        i++;
    }
    return (range);
}

// #include <stdio.h>
// int main()
// {
//     int *array;
//     array = ft_range(1, 3);
//     int i;
//     i =0;
//     while (array[i])
//     {
//         printf("%d",array[i]);
//         i++;
//     }
// }














// int *ft_range(int start, int end)
// {
//     int i = 0;
//     // Defining the lenght of the range
//     // Since we don't have access to the abs function, we have
//     // to make a manual absolute value
//     int len = (end - start) < 0 ? ((end - start) * -1) + 1 : (end - start) + 1;
//     // Allocating the range needed
//     int *range = (int *) malloc(len * sizeof(int));
    
//     // Fill in the range
//     while (i < len)
//     {
//         // Next lines are for numbers going up
//         if (start < end)
//             range[i] = start++;
//         // Next lines are for numbers going down
//         else
//             range[i] = start--;
//         i++;
//     }
//     // Returning the filled range
//     return (range);
// }