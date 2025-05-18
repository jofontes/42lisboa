#include "minitalk.h"


//if SIGUSR1  -> bit 1
//if SIGUSR2  -> bit 0
// protocol



void handler(int signo, siginfo_t *info, void *more_info)
{
    (void)more_info;


}




int main(void)
{
    printf("server PID = %d\n", getpid());

    Signal(SIGUSR1, handler, true);
    Signal(SIGUSR2, handler, true);

    while (1)
        pause;

    return EXIT_SUCCESS;
}