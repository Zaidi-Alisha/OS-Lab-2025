#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024  

int main() {
    int input_fd, output_fd, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    input_fd = open("input.txt", O_RDONLY);
    if (input_fd == -1) {
        perror("Error opening input file");
        exit(1);
    }

    output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        perror("Error opening output file");
        close(input_fd); 
        exit(1);
    }

    while ((bytes_read = read(input_fd, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("Error writing to output file");
            close(input_fd);
            close(output_fd);
            exit(1);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from input file");
    }

    close(input_fd);
    close(output_fd);

    printf("File copied successfully from input.txt to output.txt\n");

    return 0;
}//end main
