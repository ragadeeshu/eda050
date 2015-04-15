#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void usr2Handler(int sig){
	printf("\n\nSIGUSR2\n\n");
}

static void intHandler(int sig){
	printf("\n\nDid you press something?\n\n");
	signal(SIGUSR1, SIG_IGN);

	struct sigaction usr2Act;
	usr2Act.sa_handler = usr2Handler;
	sigaction(SIGUSR2, &usr2Act, NULL);

	for(;;){}

	signal(SIGUSR1, SIG_DFL);
}

int main() {
	struct sigaction intAct;
	intAct.sa_handler = intHandler;
	sigaction(SIGINT, &intAct, NULL);



	while(1){

    unsigned int time_to_sleep = 1; // sleep 1 seconds
    while(time_to_sleep){
    	printf("Tick...\n");
    	time_to_sleep = sleep(time_to_sleep);
    }
}
}
