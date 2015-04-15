#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	sigset_t fullset;
	sigfillset(&fullset);

	sigset_t blockset;
	sigemptyset(&blockset);
	sigaddset(&blockset, SIGUSR1);
	sigaddset(&blockset, SIGTSTP); // ^Z
	sigaddset(&blockset, SIGINT); // ^Z
	sigprocmask(SIG_BLOCK, &blockset, NULL);

	sigset_t pendset;

	printf("Entering 5 second loop...\n");
    unsigned int time_to_sleep = 5; // sleep 5 seconds
    while(time_to_sleep){
    	time_to_sleep = sleep(time_to_sleep);
    }
    printf("...leaving loop\n");

    sigpending(&pendset);

    int sig;
    for(sig = 0; sig < NSIG; sig++){
    	if(sigismember(&pendset, sig))
    		printf("Blocked signal: %s\n", strsignal(sig));
    }
}
