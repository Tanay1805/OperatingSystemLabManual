#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("holidays.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *last_token = NULL;
        char *token = strtok(line, " \t");
        while (token != NULL) {
            last_token = token;
            token = strtok(NULL, " \t");
        }
        if (last_token) {
            printf("%s\n", last_token);
        }
    }

    fclose(file);
    return 0;
}

