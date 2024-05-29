#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("new_file.txt", O_CREAT | O_WRONLY, 0644);
    
    if (fd == -1) {
        printf("Error creating the file!\n");
        return 1;
    }
    
    printf("File created and opened successfully.\n");
    
    close(fd);
    
    return 0;
}
