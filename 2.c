#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *filename = "testfile.txt";
    uid_t new_owner = 1000; // UID of the new owner, replace with desired UID

    // Create a file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }
    fclose(file);

    // Change file owner
    if (chown(filename, new_owner, -1) == -1) {
        perror("Error changing owner");
        return 1;
    }

    printf("Owner changed successfully.\n");

    return 0;
}

