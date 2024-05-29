#include <stdio.h>

int main() {
    FILE *source = fopen("eager.txt", "r");
    FILE *dest = fopen("notEager.txt", "w");
    char buffer[256];
    size_t bytes;
    
    if (source == NULL || dest == NULL) {
        printf("Error opening files!\n");
        return 1;
    }
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(source);
    fclose(dest);
    
    printf("File copied successfully.\n");
    
    return 0;
}
