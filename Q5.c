#include <stdio.h>

int main() {
    FILE *fp = fopen("eager.txt", "w");
    
    if (fp == NULL) {
        printf("Error creating the file!\n");
        return 1;
    }
    
    fprintf(fp, "Hello, World!\n");
    fclose(fp);
    
    printf("Successfully wrote to the file.\n");
    
    return 0;
}
