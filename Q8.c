#include <stdio.h>
#include <string.h>

int main() {
    // Open the original file and the temporary file
    FILE *file = fopen("holidays.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Error opening file");
        if (file) fclose(file);
        if (temp) fclose(temp);
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Check if the line contains the word "error"
        if (strstr(line, "error") == NULL) {
            // Write the line to the temporary file if "error" is not found
            fputs(line, temp);
        }
    }

    // Close both files
    fclose(file);
    fclose(temp);

    // Remove the original file
    if (remove("holidays.txt") != 0) {
        perror("Error removing original file");
        return 1;
    }

    // Rename the temporary file to the original file name
    if (rename("temp.txt", "holidays.txt") != 0) {
        perror("Error renaming temporary file");
        return 1;
    }

    return 0;
}
