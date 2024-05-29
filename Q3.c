#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("holidays.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int column_count = 0;
        char *token = strtok(line, " \t");
        int third_column_value = 0;
        while (token != NULL) {
            column_count++;
            if (column_count == 3) {
                third_column_value = atoi(token);
                break;
            }
            token = strtok(NULL, " \t");
        }
        if (third_column_value > 50) {
            printf("%s", line);
        }
    }

    fclose(file);
    return 0;
}

