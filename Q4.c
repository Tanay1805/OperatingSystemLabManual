#include <stdio.h>

int main() {
    FILE *fp;

    // Read mode
    fp = fopen("eager.txt", "r");
    if (fp != NULL) {
        printf("Opened file in read mode.\n");
        fclose(fp);
    }

    // Write mode
    fp = fopen("eager.txt", "w");
    if (fp != NULL) {
        printf("Opened file in write mode.\n");
        fclose(fp);
    }

    // Append mode
    fp = fopen("eager.txt", "a");
    if (fp != NULL) {
        printf("Opened file in append mode.\n");
        fclose(fp);
    }

    // Read and write mode
    fp = fopen("eager.txt", "r+");
    if (fp != NULL) {
        printf("Opened file in read and write mode.\n");
        fclose(fp);
    }

    // Write and read mode
    fp = fopen("eager.txt", "w+");
    if (fp != NULL) {
        printf("Opened file in write and read mode.\n");
        fclose(fp);
    }

    return 0;
}
