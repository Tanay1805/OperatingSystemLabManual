#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[11];
    
    fd = open("eager.txt", O_RDONLY);
    
    if (fd == -1) {
        printf("Error opening the file!\n");
        return 1;
    }
    
    int bytes_read = read(fd, buffer, 10);
    if (bytes_read == -1) {
        printf("Error reading the file!\n");
        close(fd);
        return 1;
    }
    
    buffer[bytes_read] = '\0';
    
    printf("First %d bytes of the file: %s\n", bytes_read, buffer);
    
    close(fd);
    
    return 0;
}
