#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        for (int i = 0; i < 100; i++) {
            printf("I am a child process\n");
        }
        exit(0); 
    } 

    else {
        for (int i = 0; i < 100; i++) {
            printf("I am a parent process\n");
        }

        wait(NULL);

        printf("Parent process terminating\n");
    }

    return 0;
}//end main
