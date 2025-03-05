#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    int fd;
    char buffer[BUFSIZ];
    ssize_t num_bytes;

    // Create the named pipe (FIFO)
    mkfifo(FIFO_FILE, 0666);

    // Open FIFO for writing
    fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) { // Producer loop
        printf("Producer: Enter a message (or 'exit' to quit): ");
        fgets(buffer, BUFSIZ, stdin);

        num_bytes = write(fd, buffer, strlen(buffer));
        if (num_bytes == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Check for exit condition
        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
    }

    close(fd);          // Close the named pipe
    unlink(FIFO_FILE);  // Remove the named pipe from the file system
    return 0;
}
