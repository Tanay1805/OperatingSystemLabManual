#include <stdio.h>

int main() {
    // File pointer for handling file operations
    FILE *file;

    // Open a file for writing (creates a new file or overwrites existing)
    file = fopen("demo.txt", "w");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write data to the file
    fprintf(file, "This is a demo file.\n");
    fprintf(file, "It demonstrates basic file operations in C.\n");

    // Close the file
    fclose(file);

    // Open the file for appending (if the file exists, data is appended at the end)
    file = fopen("demo.txt", "a");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Append additional data to the file
    fprintf(file, "Appending some more data to the file.\n");

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen("demo.txt", "r");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read and print data from the file
    char buffer[100];
    while (fgets(buffer, 100, file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}
