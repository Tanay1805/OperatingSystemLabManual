#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for strtok

int main() {
    // Open the file for reading
    FILE *file = fopen("holidays.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    int sum = 0;

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Get the first token (first column)
        char *token = strtok(line, " \t");
        if (token) {
            // Convert the token to an integer and add it to the sum
            sum += atoi(token);
        }
    }

    // Print the sum of the first column
    printf("Sum of first column: %d\n", sum);

    // Close the file
    fclose(file);
    return 0;
}
