#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

volatile int proceed;

static void alarmHandler(int sig){
    proceed = 0;
}

int main() {
    struct sigaction alarmAct = {0};
    alarmAct.sa_handler = alarmHandler;
    sigaction(SIGALRM, &alarmAct, NULL);

    proceed = 1;
    long count = 0;

    alarm(1);
    while(proceed){
        count++;
        // int c = count -14;
        // int huge = c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c;
        // if(count%10000000 == 0)
        //     printf("\nIterations: %d\n", count);
    }
    printf("\nIterations: %ld\n", count);

}
