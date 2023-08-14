#include <stdio.h>
#include <stdint.h>

#define TINT       1
#define TCHAR      2
#define TDOUBLE    3
#define TFLOAT     4
#define TUINT8     5
#define TUINT16    6
#define TUINT32    7
#define TUINT64    8

void printValue(const void* valuePtr, uint8_t flag) {

    switch (flag) {
        case TINT:
            printf("\nTINT : %d\n", *(int*)valuePtr);
            break;
        case TCHAR:
            printf("\nTCHAR : %c\n", *(char*)valuePtr);
            break;
        case TDOUBLE:
            printf("\nTDOUBLE : %lf\n", *(double*)valuePtr);
            break;
        case TFLOAT:
            printf("\nTFLOAT : %f\n", *(float*)valuePtr);
            break;
        case TUINT8:
            printf("\nTUINT8 : %u\n", *(uint8_t*)valuePtr);
            break;
        case TUINT16:
            printf("\nTUINT16 : %u\n", *(uint16_t*)valuePtr);
            break;
        case TUINT32:
            printf("\nTUINT32 : %u\n", *(uint32_t*)valuePtr);
            break;
        case TUINT64:
            printf("\nTUINT64 : %llu\n", *(uint64_t*)valuePtr);
            break;
        default:
            printf("Unknown type flag.\n");
    }
}

int main() {

    int i = 42;
    char c = 'A';
    double d = 123.456;
    float f = 789.0f;
    uint8_t u8 = 255;
    uint16_t u16 = 65535;
    uint32_t u32 = 4294967295U;
    uint64_t u64 = 18446744073709551615ULL;

    printValue(&i, TINT);
    printValue(&c, TCHAR);
    printValue(&d, TDOUBLE);
    printValue(&f, TFLOAT);
    printValue(&u8, TUINT8);
    printValue(&u16, TUINT16);
    printValue(&u32, TUINT32);
    printValue(&u64, TUINT64);

    return 0;
}

/*

    gcc -std=c11 -o task2 task2.c

    ./task2


*/