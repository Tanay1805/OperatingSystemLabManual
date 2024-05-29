#include <stdio.h>

int main() {
    FILE *file = fopen("holidays.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    int line_number = 1;
    while (fgets(line, sizeof(line), file)) {
        fputs(line, temp);
        if (line_number == 5) {
            fputs("Appended line after fifth line\n", temp);
        }
        line_number++;
    }

    fclose(file);
    fclose(temp);

    remove("holidays.txt");
    rename("temp.txt", "holidays.txt");

    return 0;
}
