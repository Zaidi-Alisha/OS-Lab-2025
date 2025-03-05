#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 == -1) {
        perror("Fork failed for first child");
        exit(1);
    }

    if (pid1 == 0) {
        printf("Child 1 PID: %d\n", getpid());
        exit(0);  
    }

    pid2 = fork();

    if (pid2 == -1) {
        perror("Fork failed for child 2");
        exit(1);
    }

    if (pid2 == 0) {
        printf("Child 2 PPID: %d\n", getppid());
        exit(0);  
    }

    wait(NULL);  
    wait(NULL);  

    printf("Parent process terminating\n");

    return 0;
}//end main
