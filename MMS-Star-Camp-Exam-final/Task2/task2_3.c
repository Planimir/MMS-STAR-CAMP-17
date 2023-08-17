#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
 
typedef struct {
    char* filename;
    uint64_t sum;
} ThreadData;
 
uint64_t sumOfDigits(uint64_t num) {
    uint64_t sum = 0;
    while(num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
 
void* processFile(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    FILE *file = fopen(data->filename, "rb");
 
    if (!file) {
        perror(data->filename);
        pthread_exit(NULL);
    }
 
    uint64_t num;
    data->sum = 0;
    while(fread(&num, sizeof(uint64_t), 1, file) == 1) {
        data->sum += sumOfDigits(num);
    }
    fclose(file);
 
    pthread_exit(NULL);
}
 
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }
 
    int numFiles = argc - 1;
    pthread_t threads[numFiles];
    ThreadData threadData[numFiles];
 
    for (int i = 0; i < numFiles; i++) {
        threadData[i].filename = argv[i+1];
        pthread_create(&threads[i], NULL, processFile, &threadData[i]);
    }
 
    uint64_t totalSum = 0;
    for (int i = 0; i < numFiles; i++) {
        pthread_join(threads[i], NULL);
        totalSum += threadData[i].sum;
        printf("%s - %lu\n", threadData[i].filename, threadData[i].sum);
    }
 
    printf("Total sum of digits - %lu\n", totalSum);
 
    return EXIT_SUCCESS;
}

/*
    gcc task2_3.c -lpthread -o task2_3 -Wall -Wextra


*/