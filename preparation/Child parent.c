    fd1 = open("test.txt", O_RDONLY);
    if (fd1 < 0) {
        printf("Error opening test.txt\n");
        return 1;
    }

    // Step 2: Read data from test.txt
    int bytes_read = read(fd1, buffer, sizeof(buffer) - 1);  // -1 to leave space for '\0'
    if (bytes_read < 0) {
        printf("Error reading file\n");
        close(fd1);
        return 1;
    }
    if (bytes_read == 0) {
        printf("File is empty.\n");
        close(fd1);
        return 1;
    }
    buffer[bytes_read] = '\0';  // Null terminate for safety

    // Step 3: Open/Create "output.txt" in Write Mode (Append mode to prevent overwriting)
    fd2 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        printf("Error opening output.txt\n");
        close(fd1);
        return 1;
    }

    // Step 4: Write data to output.txt
    int bytes_written = write(fd2, buffer, bytes_read);
    if (bytes_written < 0) {
        printf("Error writing to output.txt\n");
        close(fd1);
        close(fd2);
        return 1;
    }

    // Step 5: Close both files
    close(fd1);
    close(fd2);

    printf("File copied successfully!\n");
    return 0;
}
