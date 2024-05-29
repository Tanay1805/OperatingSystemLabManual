#include <stdio.h>

int main() {
    FILE *fp = fopen("eager.txt", "r");
    char c;
    int lines = 0;
    
    if (fp == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }
    
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }
    
    fclose(fp);
    
    printf("Number of lines: %d\n", lines);
    
    return 0;
}
