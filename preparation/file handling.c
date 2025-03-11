#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    // Open input file for reading
    int inputFile = open("input.txt", O_RDONLY);
    if (inputFile == -1) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open output file for writing (create if not exists, truncate if exists)
    int outputFile = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (outputFile == -1) {
        perror("Error opening output file");
        close(inputFile);
        exit(EXIT_FAILURE);
    }

    // Read from input file and write to output file
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    while ((bytesRead = read(inputFile, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(outputFile, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to output file");
            close(inputFile);
            close(outputFile);
            exit(EXIT_FAILURE);
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from input file");
        close(inputFile);
        close(outputFile);
        exit(EXIT_FAILURE);
    }

    // Close input and output files
    if (close(inputFile) == -1) {
        perror("Error closing input file");
        exit(EXIT_FAILURE);
    }
    if (close(outputFile) == -1) {
        perror("Error closing output file");
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully.\n");
    return 0;
}