#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hex(FILE* fp) {
    unsigned char buffer;
    while (fread(&buffer, sizeof(buffer), 1, fp)) {
        printf("%02x ", buffer);
    }
    printf("\n");
}

void print_binary(FILE* fp) {
    unsigned char buffer;
    while (fread(&buffer, sizeof(buffer), 1, fp)) {
        for (int i = 7; i >= 0; --i) {
            putchar((buffer & (1 << i)) ? '1' : '0');
            if (i % 8 == 0)
                putchar(' ');
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s filename print_mode\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* fp = fopen(argv[1], "rb");
    if(!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if(strcmp(argv[2], "-H") == 0) {
        print_hex(fp);
    } else if(strcmp(argv[2], "-B") == 0) {
        print_binary(fp);
    } else {
        fprintf(stderr, "Invalid print mode. Use -H for hex and -B for binary.\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return 0;
}

/*

    gcc -Wall -Wextra -o my_xxd ex_01.c

    ./my_xxd file -H

    ./my_xxd file -B
*/