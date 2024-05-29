#include <stdio.h>

int main() {
    FILE *fp = fopen("existing_file.txt", "a");
    
    if (fp == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }
    
    fprintf(fp, "End of File\n");
    fclose(fp);
    
    printf("Successfully appended to the file.\n");
    
    return 0;
}
