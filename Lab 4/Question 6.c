#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_alarm(int sig) {
    printf("Alarm received! Terminating the program...\n");
    exit(0);  
}

int main() {
    signal(SIGALRM, handle_alarm);

    alarm(5);

    for (int i = 1; i <= 5; i++) {
        printf("Message #%d: Waiting for the alarm...\n", i);
        sleep(1);  
    }

    printf("Program completed without receiving an alarm.\n");

    return 0;
}//end main
