#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>



// int main()
// {
//     int fd;

//     fd = open("text.txt", O_RDWR);
//     printf("fd of fil %d\n", fd);
    
//     write(1, "hello", 5);
//     write(fd, "hello", 5);
//     write(1, "\n", 1);
//     return 0;
// }







int main()
{
    int fd;
    char buf[256];
    int chars_read;
    fd = open("text.txt", O_RDONLY);
    
    while (read(fd, buf, 25))
    {
		chars_read = read(fd, buf, 25);
        buf[chars_read] = '\0';
        printf("%s\n", buf);
    }


    write(1, "\n", 1);
    return 0;
}	