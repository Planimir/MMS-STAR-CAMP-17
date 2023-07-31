#include <stdio.h>
#include <stdint.h> // Include this header for uint16_t
#include <stdbool.h> 

void SetBit(unsigned short* num, int bitIndex) {
    if (bitIndex >= 0 && bitIndex <= 15) {
        unsigned short mask = 1 << bitIndex;
        *num = *num | mask;
    }
}

int checkBit(uint16_t mask, int bitIndex) {
    return (mask & (1u << bitIndex)) ? 1 : 0;
}

void printBits(uint16_t mask) {
    for (int i = 16 - 1; i >= 0; i--) {
        printf("%d", checkBit(mask, i));
    }
    printf("\n");
}

unsigned int clearBit(unsigned int num, int pos) {
    if (pos >= 0 && pos < 16) {
        unsigned int mask = ~(1u << pos);
        return num & mask;
    } else {
        printf("\nInvalid bit position. Bit position must be between 0 and 15.\n");
        return num;
    }
}

int main(int argc, char* argv[]) {
    unsigned short numberSetBit = 0;
    short bitIndex = 5;
    short number = 10;

    printf("\nSet bit\n");
    printf("Before setting bit %d: %u\n", bitIndex, number);
    SetBit(&number, bitIndex);
    printf("After setting bit %d: %u\n", bitIndex, number);

    uint16_t numberPrintBits = 0b1100101101010101;
    printf("\nPrint Bits\n");
    printBits(numberPrintBits);

    unsigned short numberClearBit = 0b1100101101010101;
    unsigned short result = clearBit(number, bitIndex);

    printf("\nClear Bit\n");
    printf("Original number: %u", number);
    printf("\nNumber with bit at position %d cleared: %u\n", bitIndex, result);

    return 0;
}
