#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

uint64_t sumOfDigits(uint64_t num) {
    uint64_t sum = 0;
    while(num) {
        sum += num % 10;
        num /= 10;
    }
    // printf("DEBUG: Sum = %lu\n", sum);
    return sum;
}

int main(int argc, char **argv) {
    uint64_t totalSum = 0;

    for(int i = 1; i < argc; i++) {
        int fd[2];
        if(pipe(fd) == -1) {
            perror("An error occurred with the file descriptor of the pipe");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();

        if(pid == -1) {
            perror("An error occurred with the process creation");
            exit(EXIT_FAILURE);
        } else if(pid == 0) {
            // child
            close(fd[0]);
            FILE *file = fopen(argv[i], "rb");

            if(!file) {
                dprintf(fd[1], "ERROR: %d", errno);
            } else {
                uint64_t num, sum = 0;
                while(fread(&num, sizeof(uint64_t), 1, file) == 1) {
                    sum += num;
                }

                if (ferror(file)) {
                    dprintf(fd[1], "ERROR: %d", errno);
                } else {
                    dprintf(fd[1], "OK: %lu", sum);
                }
                fclose(file);
            }
            close(fd[1]);
            exit(EXIT_SUCCESS);

        } else {
            // parent
            close(fd[1]);
            char buffer[64];
            int nbytes = read(fd[0], buffer, sizeof(buffer) - 1);
            buffer[nbytes] = '\0';

            char status[6];
            uint64_t sum;
            sscanf(buffer, "%5[^:]:%lu", status, &sum);

            if (strcmp(status, "ERROR") == 0) {
                if(sum == EACCES) {
                    printf("%s - Permission denied\n", argv[i]);
                } else {
                    printf("%s - %s\n", argv[i], strerror((int)sum));
                }
            } else {
                totalSum += sum;
                printf("%s - %lu\n", argv[i], sum);
            }
            close(fd[0]);
            wait(NULL);
        }
    }
    printf("Total sum of digits - %lu\n", totalSum);
    return EXIT_SUCCESS;
}

/*

    gcc task2_2.c -o task2_2 -Wall -Wextra

    ./task2_2 file1.bin file2.bin file3.bin file4.bin file5.bin

    chmod 000 file4 to remove file4's permission to be readen.

    chmod 644 file4 to reverse the change of permissions.



*/
