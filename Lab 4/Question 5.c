#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process is executing 'ls' to list files in the current directory:\n");
        
        execlp("ls", "ls", "-l", (char *)NULL);

        perror("execlp failed");
        exit(1);
    } 
    else {
        wait(NULL);

        printf("Parent process: Child process terminated.\n");
    }

    return 0;
}//end main
