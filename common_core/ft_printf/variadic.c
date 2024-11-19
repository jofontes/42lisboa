#include <stdarg.h>
#include <stdio.h>


int average(int  n, ...)
{
    va_list ap; //ap - argument pointer, ap is pointing to the first argument
    float total;
    int i;

    total = 0;
    i = 0;
    va_start(ap, n); // skipping the n, saltar o n

    while (i < n)
    {
        total += va_arg(ap, int);
        i++;
    }
    return ((float)total/n);
}

int main()
{
    int average_age;

    average_age = average(3, 10, 15, 20);
    printf("The average age of those 3 people is %d\n", average_age);

}