#include <stdio.h>
#include <unistd.h> // This header is needed for the access() function

int main() {
    // Check if the file exists
    if (access("eager.txt", F_OK) != -1) {
        printf("File exists.\n");
    } else {
        printf("File does not exist.\n");
    }

    return 0;
}

