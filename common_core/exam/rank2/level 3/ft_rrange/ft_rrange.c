#include <stdlib.h>


int *ft_rrange(int start, int end)
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
        if (end < start)
            range[i] = end++;
        else
            range[i] = end--;
        i++;
    }
    return (range);
}

// #include <stdio.h>
// int main()
// {
//     int *array;
//     array = ft_rrange(1, 3);
//     int i;
//     i =0;
//     while (array[i])
//     {
//         printf("%d",array[i]);
//         i++;
//     }
// }








