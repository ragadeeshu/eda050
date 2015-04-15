#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int proceed;

static void alarmHandler(int sig){
    proceed = 0;
}

int main() {
    struct sigaction alarmAct;
    alarmAct.sa_handler = alarmHandler;
    sigaction(SIGALRM, &alarmAct, NULL);

    proceed = 1;
    int count = 0;

    alarm(1);
    while(proceed){
        count++;
        int c = count -14;
        int huge = c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c;
        if(count%10000000 == 0)
            printf("\nIterations: %d\n", count);
    }
    printf("\nIterations: %d\n", count);

}
