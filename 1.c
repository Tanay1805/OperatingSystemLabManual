
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int file_desc = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_desc < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Duplicate the file descriptor
    int dup_desc = dup(file_desc);
    if (dup_desc < 0) {
        perror("dup");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    // Write to the original file descriptor
    if (write(file_desc, "Writing to original file descriptor\n", 37) < 0) {
        perror("write");
        close(file_desc);
        close(dup_desc);
        exit(EXIT_FAILURE);
    }

    // Write to the duplicated file descriptor
    if (write(dup_desc, "Writing to duplicated file descriptor\n", 39) < 0) {
        perror("write");
        close(file_desc);
        close(dup_desc);
        exit(EXIT_FAILURE);
    }

    // Close both file descriptors
    close(file_desc);
    close(dup_desc);

    return 0;
}
