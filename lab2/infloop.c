#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void intdo(int sig){
  printf("\n\nDid you press something?\n\n");
}

int main() {
  signal(SIGINT, intdo);

  while(1){

    unsigned int time_to_sleep = 1; // sleep 1 seconds
    while(time_to_sleep){
      printf("Tick...\n");
      time_to_sleep = sleep(time_to_sleep);
    }
  }
}
