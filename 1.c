#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    char *filename = "testfile.txt";
    mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // Read and write for user, read for group and others

    // Create a file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }
    fclose(file);

    // Set file permissions
    if (chmod(filename, permissions) == -1) {
        perror("Error setting permissions");
        return 1;
    }

    printf("Permissions set successfully.\n");

    return 0;
}
