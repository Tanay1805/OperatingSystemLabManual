#include <stdio.h>
#include <string.h>

void replaceAll(char *str, const char *oldWord, const char *newWord) {
    char *pos, temp[256];
    int index = 0;
    int owlen = strlen(oldWord);

    while ((pos = strstr(str, oldWord)) != NULL) {
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, newWord);
        strcat(str, temp + index + owlen);
    }
}

int main() {
    FILE *file = fopen("holidays.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        replaceAll(line, "foo", "bar");
        fputs(line, temp);
    }

    fclose(file);
    fclose(temp);

    remove("file.txt");
    rename("temp.txt", "file.txt");

    return 0;
}

