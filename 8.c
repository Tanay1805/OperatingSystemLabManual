#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_KEY 1234
#define NUM_SEMS 1

int main() {
    int semid, pid;
    struct sembuf semaphore;

    // Creating a semaphore set with one semaphore
    semid = semget(SEM_KEY, NUM_SEMS, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Initialize the semaphore to 1 (unlocked)
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    // Forking a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        printf("Child process waiting...\n");
        
        // Decrement semaphore
        semaphore.sem_num = 0;
        semaphore.sem_op = -1;
        semaphore.sem_flg = 0;
        if (semop(semid, &semaphore, 1) == -1) {
            perror("semop");
            exit(EXIT_FAILURE);
        }
        
        printf("Child process resumed.\n");

        // Cleanup
        if (semctl(semid, 0, IPC_RMID) == -1) {
            perror("semctl");
            exit(EXIT_FAILURE);
        }
    } else { // Parent process
        printf("Parent process performing some task...\n");
        
        // Perform some task
        
        // Increment semaphore
        semaphore.sem_num = 0;
        semaphore.sem_op = 1;
        semaphore.sem_flg = 0;
        if (semop(semid, &semaphore, 1) == -1) {
            perror("semop");
            exit(EXIT_FAILURE);
        }

        printf("Parent process done.\n");
    }

    return 0;
}
