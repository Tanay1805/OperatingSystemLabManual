#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd = open("eager.txt", O_RDONLY);
    char buffer[11];
    struct stat st;

    if (fd == -1) {
        printf("Error opening the file!\n");
        return 1;
    }

    if (fstat(fd, &st) == -1) {
        printf("Error getting the file size!\n");
        close(fd);
        return 1;
    }

    off_t filesize = st.st_size;
    lseek(fd, filesize - 10, SEEK_SET);

    int bytes_read = read(fd, buffer, 10);
    if (bytes_read == -1) {
        printf("Error reading the file!\n");
        close(fd);
        return 1;
    }

    buffer[bytes_read] = '\0';
    printf("Last %d bytes of the file: %s\n", bytes_read, buffer);

    close(fd);

    return 0;
}
