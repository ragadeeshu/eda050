#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	sigset_t fullset;
	sigfillset(&fullset);

	sigset_t blockset;
	sigemptyset(&blockset);
	sigaddset(&blockset, SIGUSR1);
	sigaddset(&blockset, SIGTSTP); // ^Z
	sigprocmask(SIG_BLOCK, &blockset, NULL);

	sigset_t pendset;

	printf("Entering 5 second loop...\n");
    unsigned int time_to_sleep = 5; // sleep 5 seconds
    while(time_to_sleep){
    	time_to_sleep = sleep(time_to_sleep);
    }
    printf("...leaving loop\n");

    sigpending(&pendset);
    if(sigismember(&pendset, SIGTSTP))
    	printf("SUSPEND\n");
}
