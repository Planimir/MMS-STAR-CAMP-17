#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void writeSingleNumber(const char *filename, uint64_t N);

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <N>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    uint64_t N = strtoull(argv[2], NULL, 10);
    writeSingleNumber(filename, N);

    return EXIT_SUCCESS;
}

void writeSingleNumber(const char *filename, uint64_t N) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(&N, sizeof(uint64_t), 1, file);
    fclose(file);
}



/*

    
    gcc task2_1.c -o task2_1 -Wall -Wextra
    
    ./task2_1 numbers.bin 10

    ghex numbers.bin

    Направете програма, която приема следните аргументи от командния ред:
    filename
    N
    Програмата записва N на брой цели неотрицателни 64 битови числа в бинарен файл с името filename. 
    Ако файл с такова име не съществува - той се създава. 
    Ако съществува - предишното му съдържание се трие. 
    Вие имате избор какви числа да запишете във файла.

*/