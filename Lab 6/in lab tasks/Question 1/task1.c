#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    // User input for write_msg
    printf("Enter message to send: ");
    fgets(write_msg, sizeof(write_msg), stdin);

    if (pipe(fd) == -1) { // create a pipe
        fprintf(stderr, "Pipe failed\n");
        return 1;
    }

    pid = fork(); // create a new process
    if (pid < 0) { // error occurred
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }

    if (pid > 0) { // parent process
        close(fd[READ_END]); // close the unused read end
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1); // write to the pipe
        close(fd[WRITE_END]); // close write end of the pipe
    } else { // child process
        close(fd[WRITE_END]); // close the unused write end
        read(fd[READ_END], read_msg, BUFFER_SIZE); // read from the pipe
        printf("Read: %s", read_msg); // display the message
        close(fd[READ_END]); // close the read end of the pipe
    }

    return 0;
}
